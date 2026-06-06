#include "e4.h"

int lcm(int x, int y) {
    int edi = x;
    int ebx = y;
    int ecx = ebx;
    if (edi > ebx){
        ecx = edi;
    }
    L:
    int eax = ecx;
    int ah = (eax % edi == 0);
    int al = (eax % ebx == 0);
    if (ah && al){
        eax = ecx;
        return eax;
    }
    ecx++;
    goto L;

}