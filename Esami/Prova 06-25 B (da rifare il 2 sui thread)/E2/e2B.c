#include "e2B.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct thread_info{
    pthread_t thread_id;
    //int* lunghezza;
    int lunghezza;
    const char* paragrafi;
};

void* worker(void* arg){
    struct thread_info *dati = arg;
    pthread_t id = dati->thread_id;
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
    dati->lunghezza = max +1;
    //printf("Sono %d e max = %d\n",id,(*lunghezzadascrivere));
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
    *lunghezzaFraseMaxPerParagrafo = calloc(numparagrafi,sizeof(int));
    int* arraydaritornare = calloc(sizeof(int),numparagrafi);
    pthread_t threads[numparagrafi];
    struct thread_info **dati = malloc(sizeof(struct thread_info*)*numparagrafi);
    for (int i = 0;i<numparagrafi;i++){
        dati[i] = malloc(sizeof(struct thread_info));
        dati[i]->thread_id = i;
        dati[i]->paragrafi = paragrafi[i];
        pthread_create(&threads[i],NULL,worker, dati[i]);
    }

    for (int i = 0;i<numparagrafi;i++){
        pthread_join(threads[i],NULL);
        (*lunghezzaFraseMaxPerParagrafo)[i] = (dati)[i]->lunghezza;
    }
    *numeroParagrafi = numparagrafi;
}