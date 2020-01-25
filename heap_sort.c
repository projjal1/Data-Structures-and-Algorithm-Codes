#include <stdio.h> 
#include <stdlib.h>

 
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) //Max heap
{ 
    int root = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[root]) 
        root = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[root]) 
        root = r; 
  
    // If largest is not root 
    if (root != i) 
    { 
        int tmp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=tmp;  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, root); 
    } 
} 

/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i=0; i<n; ++i) 
        printf("%d ",arr[i]); 
    printf("\n"); 
}
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    int i=0;
    // Build heap (rearrange array) 
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    
    printArray(arr, n); 

    // One by one extract an element from heap 
    for (i=n-1; i>=0; i--) 
    { 
        printf("\nPass %d\n",n-i);
        // Move current root to end 
        //swap(arr[0], arr[i]);
        int tmp=arr[i];
        arr[i]=arr[0];
        arr[0]=tmp;   

        printArray(arr, n); 

        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 

        printArray(arr, n); 
    }
} 
 
  
// Driver program 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, n); 
} 