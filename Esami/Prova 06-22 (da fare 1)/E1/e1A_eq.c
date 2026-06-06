#include "e1A.h"

int crc32(char *bytes, int n){
	int ebx = 0;
	int edi = 0xFFFFFFFF;
	char* ebp = bytes;
	int eax;

	A:
	if (ebx>=n){
		goto R;
	}
	int edx = ebp[ebx]; // edx = byte
	edi = edi^edx; //edi = crc
	int esi = 0;
	B:
	if (esi < 8){
	int ecx = edi; //ecx = mask
	ecx = ecx & 1;
	ecx = -ecx;
	edi = edi >> 1;
	ecx = ecx & 0xEDB88320;
	edi = edi ^ ecx;
	esi++;
	goto B;
	}
	ebx++;
	goto A;

	R:
	eax = edi;
	eax = ~eax;
	return eax;
}
