#include "e2A.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int score = 0;
int trials = 0;

static void test(const char** array, int n, int l, int correctResult) {
    trials++;

    int ok = 0;
    int maxFrasi = 0;

    int res = countCouples(array, n, l);
    // printf("test: %d, n: %d, l: %d, result: %d, expected result: %d\n", trials , n, l, res, correctResult);fflush(stdout);
    
    ok = res == correctResult;
    // printf("Test %d: %s\n", trials, ok ? "OK" : "errore");fflush(stdout);
    printf("Test %d: %d [corretto=%d] -> %s\n", trials, res, correctResult, correctResult == res ? "OK" : "errore" );
    
    score += ok;
}

int main() {
    const char * array0[] = {"hello", "world", "hello world", NULL};
    const char * array1[] = {"I am tired of weakness", "tired of my feet of clay", "tired of days to come", "tired of digital distractions", NULL};
    const char * array2[] = {"I am tired of weakness", "tired of my feet of clay", " tired of days to come", "tired of digital distractions", NULL};
    const char * array3[] = {"same string", "same string", "same string", "same string", "same string", "same string", NULL};
    const char * array4[] = {NULL};

    test(array0, 3, 3, 2);
    test(array0, 3, 6, 0);
    test(array0, 1, 3, -1);
    test(array1, 4, 1, 6);
    test(array1, 4, 5, 6); 
    test(array1, 4, 10, 2);
    test(array1, 4, 11, 0);
    test(array1, 3, 5, 2);
    test(array1, 6, 5, -1);
    test(array2, 4, 1, 2);
    test(array2, 4, 100, 0);
    test(array3, 6, 11, 30); 
    test(array3, 6, 12, 0); 
    test(array3, 8, 11, -1);
    test(array4, 1, 1, -1);

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
