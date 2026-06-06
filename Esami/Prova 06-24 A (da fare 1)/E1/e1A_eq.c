#include "e1A.h"

unsigned char* deleetify(unsigned char* v, unsigned len){
    
    unsigned char* esi = v;
    unsigned ebp = len;
    unsigned ebx = 0; //i
    unsigned char* edi = malloc(ebp);
    
    A:
    if (ebx >= ebp){
        goto R;
    }
    char cl = esi[ebx];
    if (cl > 57){
        edi[ebx] = cl;
        ebx++;
        goto A;
    }
    L:
    char eax = deleetify_helper(cl);
    edi[ebx] = eax;
    ebx++;
    goto A;

    R:
    return edi;

}