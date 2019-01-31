#include "header.h"

char *getXor(char *a, char *b)
{
	int i = -1;

	while (++i < 6)
		a[i] = a[i] == b[i] ? '0' : '1';
	return (a);
}

int toInt(char *bits)
{
    char* start = bits;

    int total = 0;
    while (*start)
    {
        total *= 2;
        if (*start++ == '1') 
        total += 1;
    }
    return (total);
}