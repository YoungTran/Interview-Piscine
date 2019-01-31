#include "header.h"

void swap(struct s_art **art, int a, int b)
{
    struct s_art *tmp = art[a];
    art[a] = art[b];
    art[b] = tmp;
}

void heapify(struct s_art **arr, int i, int n) 
{ 
    int max = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && strcmp(arr[l]->name, arr[i]->name) > 0)
        max = l; 
  
    // If right child is larger than largest so far 
  if (l < n && strcmp(arr[r]->name, arr[max]->name) > 0)
        max = r; 
  
    // If largest is not root 
    if (max != i) 
    { 
        swap(arr, i, max); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr , max, n); 
    } 
} 

void heapSort(struct s_art **masterpiece, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(masterpiece, i, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(masterpiece, 0 , i);
        heapify(masterpiece, 0, i);
    }
}