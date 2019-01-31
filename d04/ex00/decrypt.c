#include "header.h"

char *getSum(char *a, char *b)
{
   int i = 6;
   int add = 0;

   while (--i >= 0)
   {
       if (a[i] == '0' && b[i] == '0')
       {
           a[i] = '0' + add;
           add = 0;
       }
       else if (a[i] != b[i])
        a[i] = '1' - add;
        else{
            a[i] = '0' + add;
            add = 1;
        }
   }
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