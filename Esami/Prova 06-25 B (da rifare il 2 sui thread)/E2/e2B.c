#include "e2B.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct thread_info{
    pthread_t thread_id;
    int* lunghezza;
    const char* paragrafi;
};

void* worker(void* arg){
    struct thread_info *dati = arg;
    pthread_t id = dati->thread_id;
    int* lunghezzadascrivere = dati->lunghezza;
    const char* par = dati->paragrafi;
    char* paragrafo = (char*)par;
    int max = 0;
    char* token = strtok(paragrafo, ".");
    while (token != NULL){
        int len = strlen(token);
        if (len>max){
            max = len;
        }
        token = strtok(NULL, ".");
    }
    *lunghezzadascrivere = max +1;
    //printf("Sono %d e max = %d\n",id,(*lunghezzadascrivere));
    free(dati);
    return NULL;
}


int getParagrafi(const char* nomefile, char*** paragrafi){
    int count = 0;
    FILE* fparag = fopen(nomefile, "r");
    char buffer[1024];
    while (fgets(buffer, 1024, fparag)!=NULL){
        if (buffer[1] != 0){
            if ((*paragrafi)[count] == NULL) {
                (*paragrafi)[count] = calloc(sizeof(char), 10000);
            }
            strcat((*paragrafi)[count],buffer);
        }
        if (buffer[1] == 0){
            count++;
        }
    }
    return count+1;
}

void frasePiuLungaPerParagrafo(const char* nomefile, int* numeroParagrafi, int** lunghezzaFraseMaxPerParagrafo){
    FILE* f1 = fopen(nomefile, "r");
    char** paragrafi;
    paragrafi = calloc(sizeof(char**),1024);
    int numparagrafi = getParagrafi(nomefile,&paragrafi);
    int* arraydaritornare = calloc(sizeof(int),numparagrafi);
    pthread_t threads[numparagrafi];
    for (int i = 0;i<numparagrafi;i++){
        struct thread_info *dati = malloc(sizeof(struct thread_info));
        dati->thread_id = i;
        dati->lunghezza = &arraydaritornare[i];
        dati->paragrafi = paragrafi[i];
        pthread_create(&threads[i],NULL,worker, dati);
    }

    for (int i = 0;i<numparagrafi;i++){
        pthread_join(threads[i],NULL);
    }
    *numeroParagrafi = numparagrafi;
    printf("NumPar = %d\n", *numeroParagrafi);
    *lunghezzaFraseMaxPerParagrafo = arraydaritornare;
}