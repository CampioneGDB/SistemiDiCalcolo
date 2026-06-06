#include "e1A.h"

int count_tokens(char* str, const char* sep) {
    int ebx = 0; //cnt
    char* ebp = str;
    const char* esi = sep;
    char* edi = strtok(ebp,esi);

    W:
    if (edi == NULL){
        goto R;
    }
    ebx++;
    edi = strtok(NULL,esi);
    goto W;

    R:
    return ebx;


}