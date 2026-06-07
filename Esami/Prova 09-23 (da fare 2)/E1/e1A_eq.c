#include "e1A.h"

unsigned char* base64lessless(unsigned char *data, unsigned out_len, unsigned char* b64_table) {
    if (data == NULL){
        goto O;
    }
    if (out_len == 0){
        goto O;
    }
    unsigned char* edi = malloc(out_len); //out

    unsigned char dh = 0; //bits left
    unsigned char dl = 0; //prev bits
    unsigned char cl;
    unsigned char* esi = data;

    int ebx = 0;
    F:
    if (ebx >= out_len){
        goto R;
    }

    unsigned char ah = *esi; //item

    cl = 6-dh;
    unsigned char ch = dl; //index
    ch = ch << cl;

    cl = 2+dh;
    unsigned char bh = ah;
    bh = bh >> cl;
    ch = ch | bh;

    cl = 6-dh;
    dh = 8 - cl;
    dh = dh & 7;

    unsigned char al = 8-dh; //pos
    dl = ah;
    cl = al;
    dl = dl << cl;

    cl = al;
    dl = dl >> cl;

    if (dh < 6){
        goto J;
    }
    S:
    unsigned char* ebp = b64_table;
    cl = ebp[ch];
    edi[ebx] = cl;
    ebx++;
    goto F;

    J:
    esi += 1;
    goto S;

    O:
    edi = NULL;

    R:
    return edi;
}