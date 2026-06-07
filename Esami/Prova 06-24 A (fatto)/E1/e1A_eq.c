#include "e1A.h"

unsigned char* deleetify(unsigned char* v, unsigned len){
    unsigned ecx = len;
    unsigned char* ebp = v;
    unsigned ebx = -1;
    unsigned char* esi = malloc(ecx);
    unsigned char dl;

    F:
    ebx++;
    if (ebx>=len){
        goto R;
    }
    dl = ebp[ebx];
        if (dl > 57){
            goto E;
        }
        unsigned char dh = deleetify_helper(dl);
        esi[ebx] = dh;
        goto F;

        E:
        esi[ebx] = dl;
        goto F;

    R:
    return esi;


}