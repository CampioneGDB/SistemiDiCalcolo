#include "e1A.h"

int crc32(char *bytes, int n){

	int ebx = -1;//i
	int ebp = 0;//j
	int esi = 0xFFFFFFFF; //crc
	F1:
	ebx++;
	if (ebx>=n){
		goto RET;
	}
	char* eax = bytes;
	int edi = eax[ebx];
	esi = esi ^ edi;
	ebp = 0;
	F2:
	if (ebp>=8){
		goto F1;
	}
	int ecx = esi & 1; //mask
	ecx = -ecx;
	edi = esi >>1;
	int edx = 0xEDB88320 & ecx;
	esi = edi ^ edx;
	ebp++;
	goto F2;

	RET:
	return ~esi;

}