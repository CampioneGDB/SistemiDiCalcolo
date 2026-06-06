#include "e1A.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int score, trials;

unsigned char is_known(char c){
		if (c>=97 && c<123) //lower letter
			return 1;
		if (c>=65 && c<91) //upper letter
			return 1;
		if (c==32) //space
			return 1;
        return 0;
}


void test(char* a, int len, int expected, char* str) {
    trials++;
    int res = lower(a, len);

    printf("Test %d: (%d,%s) [corretto=(%d,%s)] -> %s\n", trials, res, a, expected, str, expected == res && !strncmp(a, str, len) ? "OK" : "errore" );
    
    score += expected == res && !strncmp(a, str, len);
}

int main() {
    char a0[] = "aAzZ";
	char a1[] = "All'esame Di";
	char a2[] = "Sistemi di Calcolo";
	char a3[] = " HO PRESO";
    char a4[] = "30! Che bello";
    char a5[] = "";
    test(a0, strlen(a0), 0, "aazz");
    test(a1, strlen(a1), 4, "all'esame Di");
    test(a2, strlen(a2), 0, "sistemi di calcolo");
    test(a3, strlen(a3), 0, " ho preso"); 
    test(a4, strlen(a4), 1, "30! Che bello");
    test(a5, strlen(a5), 0, "");

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}