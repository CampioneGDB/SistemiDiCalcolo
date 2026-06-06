// inserire il C equivalente qui...

#include "../e1A.h"

#include <string.h>
unsigned int longest_string(const char *data, int len)
{
	char *b;
	int bx = len;
	int d = 0;
	int s = -1;
L:
	if (d >= len)
		goto E;
	b = (char *)data;
	b = b + d;
	int a = call_strlen(b);
	if (a == 0)
		goto S;
	if (a <= s)
		goto S;
	s = a;
S:
	d = d + a + 1;
	goto L;
E:
	a = s;
	return a;
}