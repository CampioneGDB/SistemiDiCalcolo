#include "e2A.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <pthread.h>

typedef struct { 
    char* s1;   // stringa 1 
    char* s2;   // stringa 2 
    int l;      // lunghezza prefisso 
    int* result; // risultato del calcolo 
} ThreadData;

int contaStringhe(const char**s){
    int count = 0;
    while (s[count] != NULL){
        count++;
    }
    return count;
}

void* worker(void*arg){
    ThreadData* dati = arg;
    char*s1 = dati->s1;
    char*s2 = dati->s2;
    int l = dati->l;
    int* result = dati->result;
    printf("Test con %s, %s e l = %d, res = %d\n", s1,s2,l,strncmp(s1,s2,l));
    *result = strncmp(s1,s2,l);
    free(dati);
    return NULL;
}

int countCouples(const char** s, int k, int l){
    int len = contaStringhe(s);
    char** s2 = (char**) s;
    if (k<2 || k>len){
        return -1;
    }
    int coppiepossibili = (k*k) - k;
    pthread_t threads_set[coppiepossibili];
    int * risultati = malloc(sizeof(int)*coppiepossibili);

    int threadcurr = 0;
    for (int i = 0; i<l;i++){
        for (int j = 0;j<l;j++){
            if (i == j){
                continue;
            }
            ThreadData * dati = malloc(sizeof(ThreadData));
            dati->s1 = s2[i];
            dati->s2 = s2[j];
            dati->l = l;
            dati->result=&(risultati[i]);
            pthread_create(&threads_set[threadcurr],NULL,worker,dati);
            threadcurr++;

        }
    }

    for(int i = 0; i<coppiepossibili;i++){
        pthread_join(threads_set[i],NULL);
    }

    int ret = 0;
    for (int i = 0;i<coppiepossibili;i++){
        printf("%d\n", risultati[i]);
        if (risultati[i] == 0){
            ret++;
        }
    }
    return ret;
}

