#include "e1A.h"


void rc4_encrypt(unsigned char *sbox, unsigned char *pt, unsigned char *ct) 
{
    unsigned int edi = 0; //n
    unsigned int esi = 0; //i
    unsigned char bh = 0; //j
    unsigned char bl; //rnd

    unsigned char *ebp = pt;
    W:
    if (!*ebp){
        goto R;
    }
    esi++;
    esi = esi & 255;
    unsigned char* edx = sbox;
    bh += edx[esi];
    rc4_helper(edx,esi,bh,&bl);
    unsigned char* eax = ct;
    char ch = bl^*ebp;
    eax[edi] = ch;
    edi++;
    ebp++;
    goto W;

    R:
    return;

}