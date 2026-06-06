#include "e1A.h"

/*
La funzione prende in ingresso un array di caratteri, con la
sua relativa lunghezza, e calcola la lunghezza della stringa
non vuota più lunga contenuta nell'array.
*/

unsigned int lower(char *data, unsigned int len)
{
	for (unsigned int i = 0; i < len; i++){
		if (!is_known(data[i]))
			return i+1;
		if (data[i]>=97 && data[i]<123) //lower letter
			continue;
		if (data[i]==32) //space
			continue;
		data[i] += 32; // lower to upper
	}
	return 0;
}