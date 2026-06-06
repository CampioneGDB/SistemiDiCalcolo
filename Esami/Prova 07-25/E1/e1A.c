#include "e1A.h"

/*
La funzione prende in ingresso un array di caratteri, con la
sua relativa lunghezza, e calcola la lunghezza della stringa
non vuota più lunga contenuta nell'array.
*/

unsigned int longest_string(const char *data, int len)
{
	int index = 0;
	int max = -1;

	while (index < len)
	{
		int x = call_strlen(data + index);
		if (x > 0 && x > max)
			max = x;
		index = index + x + 1;
	}

	return max;
}