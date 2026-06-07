// Inserire il C equivalente qui (opzionale: non concorre alla valutazione)
#include "../e1A.h"

unsigned int lower(char *data, unsigned int len)
{
    unsigned int si = 0;
    unsigned int ax = 0; //azzeramento non necessario in asm
for_start:
	if (si >= len)
        goto for_exit;
    char bl = data[si];

    char al = is_known(bl);
    if (al)
        goto not_if;
    ax = si;
    ax += 1;
    goto exit;
not_if:
    if (!(bl>=97 && bl<123))  //lower letter
        goto not_if2;
    si += 1;
    goto for_start;
not_if2:
    if (bl!=32) //space
        goto not_if3;
    si += 1;
    goto for_start;
not_if3:
    bl += 32;
    data[si] = bl;
    si += 1;
    goto for_start;

	
for_exit:
    ax=0;
exit:
	return ax;
}