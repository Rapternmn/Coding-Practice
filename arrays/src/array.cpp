#include "array.h"

// TODO
// Kadane’s Algorithm : Largest Sum Contiguous Subarray
// Subarray with given sum
// Sort an array of 0s, 1s and 2s
// 



// Find the Missing Number

// You are given a list of n-1 integers and these integers are in the range of 1 to n. 
// There are no duplicates in list. One of the integers is missing in the list. 
// Write an efficient code to find the missing integer.

//Method 1 : (n)*(n-1)/2 - Total sum

int getMissingNo (int a[], int n)
{
    int i, total;
    total  = (n+1)*(n+2)/2;   
    for ( i = 0; i< n; i++)
       total -= a[i];
    return total;
}

//Method 2 : Xor method

int getMissingNo_xor(int a[], int n)
{
    int i;
    int x1 = a[0]; /* For xor of all the elements in array */
    int x2 = 1; /* For xor of all the elements from 1 to n+1 */
     
    for (i = 1; i< n; i++)
        x1 = x1^a[i];
            
    for ( i = 2; i <= n+1; i++)
        x2 = x2^i;         
    
    return (x1^x2);
}


// Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes. 

int equilibrium(int arr[], int n)
{
    int sum = 0; // initialize sum of whole array
    int leftsum = 0; // initialize leftsum
 
    /* Find sum of the whole array */
    for (int i = 0; i < n; ++i)
        sum += arr[i];
 
    for (int i = 0; i < n; ++i) 
    {
        sum -= arr[i]; // sum is now right sum for index i
 
        if (leftsum == sum)
            return i;
 
        leftsum += arr[i];
    }
 
    /* If no equilibrium index found, then return 0 */
    return -1;
}