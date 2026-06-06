
#include "e1A.h"

unsigned int longest_string(const char* data, int len){
    int ebx = 0;
    int ebp = -1;
    const char* esi = data;

    W:
    if (ebx>= len){
        goto R;
    }
    const char* ecx = esi+ebx;
    int eax = call_strlen(ecx);
    if (eax <= 0){
        goto S;
    }
    if (eax <= ebp){
        goto S;
    }
    ebp = eax;

    S:
    ebx += 1;
    ebx += eax;
    goto W;

    R:
    return ebp;
}