#include <pthread.h>

#include "e3.h"
#include <stdlib.h>

typedef struct{
    unsigned int id;
    unsigned int iterazioni;
    unsigned int valore;
} data;

unsigned int *shared_array;

void* moltiplica(void* argomento){
    data* dato = (data*) argomento;
    shared_array[dato->id] = (dato->iterazioni) * (dato->valore);
    return NULL;
}

unsigned int counting_threads(unsigned int th, unsigned int it, unsigned int val){
    shared_array = (unsigned int*) malloc(th * sizeof(unsigned int));
    pthread_t array_threads[th];
    data valori[th];

    unsigned int res = 0;

    for (int k = 0; k<th; k++){
        valori[k].id = k;
        valori[k].iterazioni = it;
        valori[k].valore = val;

        pthread_create(&array_threads[k], NULL, moltiplica, &valori[k]);
    }

    for (int k = 0; k<th; k++){
        pthread_join(array_threads[k], NULL);
        res += shared_array[k];
    }
    free(shared_array);

    return res;
}