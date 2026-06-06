#include "e1C.h"

int hextodec_sum(unsigned char *in, int *out)
{
    int ebx = 0; //sum
    int ebp = 0; //i
    int esi; // res
    int* edi = out;

    W:
    unsigned char* eax = in;
    if (!*eax){
        goto R;
    }
    hextodec_helper(eax, &esi);

    if (esi <= 0){
        goto G;
    }

    ebx += esi;

    G:
    edi[ebp] = esi;
    ebp++;
    in += 2;
    goto W;

    R:
    return ebx;

}