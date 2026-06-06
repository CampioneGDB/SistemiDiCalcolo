#include "e1A.h"

int* strings_are_upper(const char** array, int n) {
    if (n <= 0) return NULL;
    if (array == NULL) return NULL;
    const char** ebp = array;
    int ecx = n;
    int* edi = malloc(4*ecx);
    int ebx = -1;
    F:
    ebx++;
    if (ebx>=n){
        goto R;
    }
    const char* esi = ebp[ebx];
    edi[ebx] = 1;
    W:
    if (!*esi){
        goto F;
    }
    if(isupper(*esi)){
        goto S;
    }
    edi[ebx] = 0;
    goto F;

    S:
    esi+=1;
    goto W;

    R:
    return edi;


}