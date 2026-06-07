#include "../e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    const char* substring;  // puntatore all'inizio della sottostringa
    int length;             // lunghezza della sottostringa
    char c;                 // carattere da contare
    int index;              // indice del thread/sottostringa
    int count;              // numero di occorrenze trovato (output)
} ThreadArg;

void* countOccurrencesThread(void* arg) {
    ThreadArg* tArg = (ThreadArg*) arg;
    int count = 0;
    for (int i = 0; i < tArg->length; i++) {
        if (tArg->substring[i] == tArg->c) {
            count++;
        }
    }
    tArg->count = count;
    return NULL;
}

int countOccurrencesParallel(const char* s, char c, int n) {
    if (s == NULL || n <= 0) {
        return -1; // controllo errori input
    }
    
    int len = strlen(s);
    if (len == 0) {
        return -1; // stringa vuota
    }

    pthread_t* threads = malloc(n * sizeof(pthread_t));
    ThreadArg* args = malloc(n * sizeof(ThreadArg));
    if (threads == NULL || args == NULL) {
        free(threads);
        free(args);
        return -1; // errore allocazione memoria
    }

    int base_len = len / n;
    int remainder = len % n;

    // Assegna a ogni thread la sua sottostringa e parametri
    for (int i = 0; i < n; i++) {
        args[i].substring = s + i * base_len;
        args[i].length = (i == n - 1) ? (base_len + remainder) : base_len;
        args[i].c = c;
        args[i].index = i;
        args[i].count = 0;
    }

    // Crea i thread
    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, countOccurrencesThread, &args[i]);
    }

    // Attende la terminazione di tutti i thread
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cerca indice con numero massimo di occorrenze
    int max_index = 0;
    int max_count = args[0].count;
    for (int i = 1; i < n; i++) {
        if (args[i].count > max_count) {
            max_count = args[i].count;
            max_index = i;
        }
    }

    free(threads);
    free(args);

    return max_index;
}