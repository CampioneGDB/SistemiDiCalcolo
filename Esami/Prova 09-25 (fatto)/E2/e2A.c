#include "e2A.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <pthread.h>

typedef struct{
    char* s;
    char c;
    int* occurr;
} ThreadData;

void* worker(void* arg){
    ThreadData* dati = arg;
    char* s = dati->s;
    char c = dati->c;
    int* occurr = dati->occurr;

    int len = strlen(s);
    int count = 0;
    for (int i = 0;i<len;i++){
        if (s[i] == c){
            count++;
        }
    }
    *occurr = count;
    free(dati);
    return NULL;
}

int countOccurrencesParallel(const char* s, char c, int n){
    if (s==NULL || n == 0){
        return -1;
    }
    char* s2 = (char*) s;
    int len = strlen(s2);
    int lungh = len/n;
    char** stringhe = calloc(sizeof(char*),n+1);
    int *arrayoccorrenze = malloc(sizeof(int)*n);
    for (int i = 0; i<n-1; i++){
        stringhe[i] = calloc(sizeof(char),lungh+1);
        strncpy(stringhe[i],s2,lungh);
        stringhe[i][lungh] = '\0';
        s2 = s2+lungh;
    }
    stringhe[n-1] = calloc(sizeof(char),lungh+(len%n)+1);
    strcpy(stringhe[n-1],s2);

    pthread_t arraythread[n];
    for (int z = 0; z<n; z++){
        ThreadData* dati = malloc(sizeof(ThreadData));
        dati->s = stringhe[z];
        dati->c = c;
        dati->occurr = &(arrayoccorrenze[z]);
        pthread_create(&arraythread[z],NULL,worker,dati);
    }

    for (int z = 0; z<n; z++){
        pthread_join(arraythread[z], NULL);
    }

    int ret = 0;
    int max = 0;
    for (int i = 0; i<n; i++){
        if (arrayoccorrenze[i] > max){
            max = arrayoccorrenze[i];
            ret = i;
        }
    }
    return ret;
}
