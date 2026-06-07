#include "e1A.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int score, trials;

unsigned int call_strlen(const char* s) {
    return strlen(s);
}

void test(char* a, int len, int expected) {
    trials++;
    int res = longest_string(a, len);

    printf("Test %d: %d [corretto=%d] -> %s\n", trials, res, expected, expected == res ? "OK" : "errore" );
    
    score += expected == res;
}

int main() {

	char a1[] = {'\0'};
	char a2[] = {'U','n','o','\0'};
	char a3[] = {'U','n','o','\0','D','u','e','\0'};
    char a4[] = {'U','n','o','\0','D','u','e','\0','Q','u','a','t','t','r','o','\0'};

    test(a1, 1, -1);
    test(a2, 4, 3);
    test(a3, 8, 3);
    test(a4, 11, 7);

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}