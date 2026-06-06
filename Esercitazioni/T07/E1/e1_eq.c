#include "e1.h"
#include <stdio.h>

int binsearch(int* v, int n, int x){
    int eax = 0; //i = eax
    int ebx = x; //x = ebx
    int ecx = n; //j = ecx
    int* esi = v;
    E:
    if (eax>=ecx){
        goto F;
    }
    int edx = eax+ecx; //m = edx
    edx = edx >> 1;
    
    if (esi[edx] == ebx){
        printf("Ciao\n");
        goto A;
    }
    if (esi[edx] > ebx){
        goto B;
    }
    eax = edx+1;
    goto E;
    A:
        eax = 1;
        return eax;
    B:
        ecx = edx;
        goto E;
    F:
        eax = 0;
        return eax;
    
}