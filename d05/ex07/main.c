#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <iostream>
#include "header.h"

int main(int ac, char **av)
{
	char *sequence = NULL;
	int palindrome;
	int nDelete = 0;

	if (ac >= 2)
		sequence = av[1];
	if (ac >= 3)
		nDelete = atoi(av[2]);
	palindrome = 0;

	/*-------------------
	launch your test here
	--------------------*/
	
	 palindrome = isPalindrome(av[1]);
	 if (palindrome)
		printf("%d\n", palindrome);
	
	return (0);
}



// Function used for the test
// Don't go further :)
