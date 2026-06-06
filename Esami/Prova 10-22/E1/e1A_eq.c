#include "e1A.h"

char* str_to_upper(const char* s) {
    const char* ebx = s;
    char* eax;
    if (ebx == NULL){
        goto NUL;
    }
    char* ebp = strdup(ebx);
    char* esi = ebp;
    W:
    if (!*esi){
        goto R;
    }
    char bl = toupper(*esi);
    *esi = bl;
    esi++;
    goto W;

    NUL:
    eax = NULL;
    goto RET;

    R:
    eax = ebp;

    RET:
    return eax;
}