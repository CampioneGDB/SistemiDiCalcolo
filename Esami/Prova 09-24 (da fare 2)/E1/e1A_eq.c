#include "e1A.h"

int slice(char* str, int start, int end, char* res){
    
    int ebx = 0;
    int esi = end;
    char* ebp = str;
    esi -= start;
    esi -= 1;

    W:
    if (*ebp == '\0'){
        goto I;
    }
    if (ebx != start){
        goto E;
    }
    slice_helper(ebp,esi,res);
    E:
    ebx++;
    ebp++;
    goto W;

    I:
    if (ebx>=start){
        goto R;
    }
    esi = 0;

    R:
    return esi;


}