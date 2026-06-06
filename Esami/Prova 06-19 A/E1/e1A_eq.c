#include "e1A.h"

void init_matrix(short** m, unsigned n) {
    unsigned ebx = -1;
    unsigned ebp = 0;
    short** esi = m;
    unsigned edi = n;

    F1:
    ebx++;
    if (ebx>=edi){
        goto R;
    }
    ebp = 0;
    F2:
    if (ebp>=edi){
        goto F1;
    }
    short* edx = esi[ebx];
    edx[ebp] = value(ebx,ebp);
    ebp++;
    goto F2;

    R:
    return;

}