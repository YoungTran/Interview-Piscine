
#include "header.h"

char *solve(char *s, int startPointer, int leftRemoved, int rightRemoved, int k) 
{
    char dp[21000][31][31];
    int endPointer = strlen(s) - rightRemoved - (startPointer - leftRemoved) - 1;
 
    if(startPointer >= endPointer) return 1; //Base Case
 
    char *ret = dp[startPointer][leftRemoved][rightRemoved];
    if(ret != -1) return ret;
 
    ret = 0;
    //Case where extremes are equal
    if(s[startPointer] == s[endPointer]) ret = solve(s, startPointer+1, leftRemoved, rightRemoved, k);
    //Check if you can remove one more element.
    //If yes, check after removing from front and back
    if(leftRemoved + rightRemoved < k) {
        *ret |= solve(s, startPointer+1, leftRemoved+1, rightRemoved, k) || solve(s, startPointer, leftRemoved, rightRemoved+1, k);
    }
    return ret;
}

char *findPalindrome(char *sequence, int nDelete)
{
     char *ret = solve(sequence, 0, 0, 0, nDelete);

     return (ret);
}