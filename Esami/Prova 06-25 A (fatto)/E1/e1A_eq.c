// Inserire di seguito il C equivalente (opzionale: non concorre alla valutazione)
#include "e1A.h"

unsigned char fight(pokemon* p1, pokemon* p2){
    pokemon* ecx = p1;
    pokemon* edx = p2;
    short si = ecx->pf; //pf1
    short di = edx->pf; //pf2
    char bl; //res
    unsigned char bh = 0; //i
    F:
    bh++;
    bl = 0;
    if (bh > 10){
        goto R;
    }
        di = update(bh,ecx,di);
        edx = p2;
        si = update(bh,edx,si);
        bl = winner(si,di);
        if (bl < 0){
            goto F;
        }
        goto R;

    R:
    return (unsigned char) bl;
}
