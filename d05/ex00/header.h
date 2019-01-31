#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void printPossibleSlices(int pizzaSize);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

// DYNAMIC ARRAY

typedef struct s_array {
	int *content;
	int length;
	int sum;
	int capacity;
} array;

struct s_array *arrayInit(void);
int     arrayAppend(struct s_array *arr, int number);
struct s_array *arrayClone(struct s_array *arr);
void    arrayPrint(struct s_array *arr);

/*--------------------------------
  &  your own other function
  --------------------------------*/
struct s_array *arrayInit(void);
int arrayAppend(struct s_array *arr, int number);
struct s_array *arrayClone(struct s_array *arr);
void arrayPrint(struct s_array *array);

#endif
