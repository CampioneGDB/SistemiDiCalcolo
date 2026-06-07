// Inserire il C equivalente qui (opzionale: non concorre alla valutazione)
#include "e1B.h"

unsigned char check(mossa* head){

    unsigned char ebx = 0; //count
    unsigned char ebp = 0; //correct
    mossa* esi = head;
    unsigned char eax;
    W:
    if (esi == 0){
        goto R;
    }

    ebx++;
    char cl = is_valid_move(esi);
    if (cl == 0){
        goto E;
    }
    ebp++;
    E:
    esi = esi->next;
    goto W;

    R:
    if (ebx == ebp){
        goto A;
    }
    eax = 0;
    goto ret;

    A:
    eax = 1;
    goto ret;

    ret:
    return eax;


}
