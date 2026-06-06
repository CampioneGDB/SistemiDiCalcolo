#include "e1A.h"

unsigned adler32(unsigned char* data, unsigned len){
    unsigned char* eax = data;
    unsigned ecx = len;
    if (eax == NULL){
        goto O;
    }
    if (ecx == 0){
        goto O;
    }
    unsigned esi = 1; //a
    unsigned edi = 0; //b
    unsigned ebp; //k
    get_adler_constant(&ebp);

    int ebx = 0;
    
    F:
    if (ebx>=len){
        goto R;
    }
    eax = data;
    esi = esi + eax[ebx];
    esi = esi % ebp;
    edi = edi + esi;
    edi = edi % ebp;
    ebx++;
    goto F;

    O:
    edi = 0;
    goto FIN;

    R:
    edi = edi << 16;
    edi = edi | esi;

    FIN:
    return edi;


}