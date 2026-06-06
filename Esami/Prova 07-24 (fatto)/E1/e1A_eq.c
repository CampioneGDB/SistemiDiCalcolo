#include "e1A.h"

short* cond_compute(short* array, unsigned* cond, int n, short* out)
{
    int ebx = 0;
    short* ebp = out;
    short* esi = array;
    unsigned* edi = cond;

    F:
    if (ebx>=n){
        goto R;
    }
    int ecx = edi[ebx];
    if (!ecx){
        ebp[ebx] = esi[ebx];
        ebx++;
        goto F;
    }
    P:
    ebp[ebx] = compute(esi[ebx]);
    ebx++;
    goto F;

    R:
    return out;
}