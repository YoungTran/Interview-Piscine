
#include "header.h"

static void recurse(int size, array *arr, int k)
{
    arrayAppend(arr, k);
    if (arr->sum < size)
    {
        for (int i = size; i > 0; i--)
        recurse(size, arrayClone(arr), i);        
    }
    else if (arr->sum == size)
    arrayPrint(arr);
    free(arr);
    return ;
}

void printPossibleSlices(int pizzaSize)
{
    array *arr = arrayInit();

    if (pizzaSize > 0)
    {
        for (int i = pizzaSize; i > 0; i--)
            recurse(pizzaSize, arrayClone(arr), i);
    }
    free(arr);
    return ;
}