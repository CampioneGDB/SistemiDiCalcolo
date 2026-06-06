// Inserire il C equivalente qui (opzionale: non concorre alla valutazione)
#include "e1B.h"

unsigned char check(mossa* head){
    mossa* ebp = head;
    unsigned char ebx = 0;
    unsigned char esi = 0;
    unsigned char eax;
    W:
    if (ebp == 0){
        goto R;
    }
    ebx++;
    if (is_valid_move(ebp) == 0){
        goto E;
    }
    esi++;

    E:
    ebp = ebp->next;
    goto W;

    R:
    if (ebx == esi){
        goto I;
    }
    eax = 0;
    goto RET;

    I:
    eax = 1;

    RET:
    return eax;


}

