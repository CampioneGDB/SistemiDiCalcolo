#include "e2.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int i, max;

static void do_sort(int *v, int n) {
    int j;
    for (i=0; i<n; ++i)
        for (j=1; j<n; ++j)
            if (v[j-1] > v[j]) {
                int tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
}

void progress_handler(int segnale){
    printf("%0.1f%%\n", 100.0*i/max);
    ualarm(500000,0);
}

void sort(int *v, int n) {
    max = n;
    
    struct sigaction s;
    s.sa_handler = progress_handler;
    
    int r = sigaction(SIGALRM, &s, NULL);
    if (r == -1){
        perror("Errore sigaction");
        exit(EXIT_FAILURE);
    }
    ualarm(500000,0);

    do_sort(v, n);
    
    s.sa_handler = SIG_IGN;
    r = sigaction(SIGALRM, &s, NULL);
    if (r == -1){
        perror("Errore sigaction");
        exit(EXIT_FAILURE);
    }
}