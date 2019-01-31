#include "header.h"

char *getNot(char *a)
{
	for (int i = 0; i < 4; i += 1)
		a[i] = (a[i] == '1') ? '0' : '1';
	return (a);
}

char *getAnd(char *a, char *b)
{
	a = (a[0] == '~') ? getNot(a + 1) : a;
	b = (b[0] == '~') ? getNot(b + 1) : b;
	for (int i = 0; i < 4; i += 1)
		a[i] = (a[i] == '0' || b[i] == '0') ? '0' : a[i];
	return (a);
}

char *getOr(char *a, char *b)
{
	a = (a[0] == '~') ? getNot(a + 1) : a;
	b = (b[0] == '~') ? getNot(b + 1) : b;
	for (int i = 0; i < 4; i += 1)
		a[i] = (a[i] == '1' || b[i] == '1') ? '1' : a[i];
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