#include "e1A.h"
#include <stdio.h>


unsigned int* div_vectors(unsigned int* a, unsigned int* b, int n){
    unsigned int* ebp = a;
    unsigned int* edi = b;
    if (ebp == NULL) goto G;
    if (edi == NULL) goto G;
    if (n==0) goto G;
    int ecx = n*4;
    unsigned int* esi = malloc(ecx);
    int ebx = 0;
    int eax;
    F:
    if (ebx>=n){
        return esi;
    }
    
    eax = ebp[ebx];
    ecx = edi[ebx];
    int edx = 0;
    eax = eax/ecx;
    esi[ebx] = eax;
    ebx++;
    goto F;

    G:
    return NULL;
    }