#include "e1A.h"

unsigned int lower(char *data, unsigned int len){

    unsigned int ebx = 0;
    char* esi = data;
    A:
    if (ebx>=len){
        goto R;
    }
    char dh = esi[ebx];
    int ch = is_known(dh);
    ch = !ch;
    if (ch) goto B;
    ch = esi[ebx] >= 97;
    int cl = esi[ebx] < 123;
    if (ch && cl){
    ebx++;
    goto A;
    }
    ch = esi[ebx] == 32;
    if (ch){
        ebx++;
        goto A;
    }
    esi[ebx] += 32;
    ebx++;
    goto A;

    R:
    return 0;
    B:
    return ebx + 1;


}