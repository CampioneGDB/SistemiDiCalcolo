#include "e1A.h"

int slice(char* str, int start, int end, char* res){
    char* edi = str;
    char* esi = res;

    int ebx = 0;
    int ebp = end-start-1;

    W:
    if (*edi == '\0'){
        goto I;
    }
    if (ebx != start){
        goto K;
    }
    ebx++;
    slice_helper(edi,ebp,esi);
    edi++;
    goto W;
    
    K:
    ebx++;
    edi++;
    goto W;

    I:
    if (ebx >= start){
        goto R;
    }
    ebp = 0;

    R:
    return ebp;
}