#include "e1A.h"
#include <stdio.h>

int suffix(const char* a, const char* b) {
    const char* esi = a;
    const char* edi = b;

    int ebp = strlen(esi); //alen
    int edx = strlen(edi); //blen

    if (edx > ebp){
        goto O;
    }

    int ebx = ebp-edx;
    esi = a;
    edi = b;
    F:
    if (ebx>=ebp){
        goto I;
    }
    char al = esi[ebx];
    if (al != *edi){
        goto O;
    }
    edi++;
    ebx++;
    goto F;


    I:
    return 1;
    O:
    return 0;


}