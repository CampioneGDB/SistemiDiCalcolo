#include "e1A.h"

unsigned int* div_vectors(unsigned int* a, unsigned int* b, int n) {
    if (a == NULL){
        goto NUL;
    }
    if (b == NULL){
        goto NUL;
    }
    if (n == 0){
        goto NUL;
    }
    int eax = 4;
    eax *= n;

    unsigned int* ebp = malloc(eax); //out
    int ebx = 0;
    F:
    if (ebx>=n){
        goto ret;
    }
    unsigned int* esi = b;
    if (esi[ebx] == 0){
        goto CASE2;
    }
    unsigned int *edi = a;
    eax = edi[ebx];
    int ecx = esi[ebx];
    eax = eax/ecx;
    ebp[ebx] = eax;
    ebx++;
    goto F;

    CASE2:
    ebp[ebx] = 0;
    ebx++;
    goto F;


    NUL:
    ebp = NULL;
    ret:
    return ebp;


}