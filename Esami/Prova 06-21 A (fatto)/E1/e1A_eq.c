#include "e1A.h"

int count_tokens(char* str, const char* sep){
    int ebx = 0;
    char* edi = str;
    const char* ebp = sep;
    char* esi = strtok(edi,ebp);
    W:
    if (esi == NULL){
        goto R;
    }
    ebx++;
    esi = strtok(0,ebp);
    goto W;

    R:
    return ebx;
}