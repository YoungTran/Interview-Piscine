#include "header.h"

void swap(char *x, char *y) 
{ 
    char temp = *x;
    *x = *y; 
    *y = temp; 
}

int shouldSwap(char *str, int start, int curr) 
{ 
    for (int i = start; i < curr; i++)  
        if (str[i] == str[curr]) 
            return 0; 
    return 1; 
}

void permute(char *a, int l, int r) 
{ 
   int i, check;
   if (l == r) 
     printf("%s\n", a); 
   else
   { 
       for (i = l; i <= r; i++) 
       {
        if ((check = shouldSwap(a, l, i)))
        {
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i)); //backtrack 
        }
       } 
   } 
} 

void printUniquePermutations(char *s)
{
    permute(s, 0, strlen(s) - 1);
}