#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_people
{
	char *name; 
	int time; //in minute
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int isPossible(struct s_people **people, int nbTable, int totalTime);

/*-----------------------------s---
  ?? test function used in main 
  --------------------------------*/
struct s_people **readGuestList();


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
