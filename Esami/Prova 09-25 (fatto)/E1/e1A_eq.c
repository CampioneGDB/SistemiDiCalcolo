#include "e1A.h"

unsigned int lower(char *data, unsigned int len){
    char* ebp = data;

    unsigned int ebx = -1;

    F:
    ebx++;
    if (ebx>=len){
        goto O;
    }
    char dl = ebp[ebx];
    if (!is_known(dl)){
        goto I1;
    }
    char cl = ebp[ebx]>=97;
    char ch = ebp[ebx]<123;
    cl = cl && ch;
    if (cl){
        goto F;
    }
    cl = ebp[ebx]==32;
    if (cl){
        goto F;
    }
    ebp[ebx] += 32;
    goto F;

    I1:
    ebx++;
    goto R;

    O:
    ebx = 0;

    R:
    return ebx;

}