#include "e1A.h"
#include <stdio.h>

int suffix(const char* a, const char* b) {
    const char* eax = a;
    int esi = strlen(eax);
    const char* ebp = b;
    int edi = strlen(ebp);
    int edx;

    if (edi>esi){
        goto O;
    }

    int ebx = esi;
    ebx = ebx-edi;
    F:
    if (ebx>=esi){
        printf("Stampo 1\n");
        goto I;
    }
    eax = a;
    if (eax[ebx] != *ebp){
        printf("Stampo 0 sotto\n");
        goto O;
    }
    ebp++;
    ebx++;
    goto F;


    O:
    edx = 0;
    goto R;

    I:
    edx = 1;

    R:
    return edx;

}