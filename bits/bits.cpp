#include "bits.h"

int countSetBits(int n) 
{ 
    // base case 
    if (n == 0)
        return 0;

    else
        // if last bit set add 1 else add 0
        return (n & 1) + countSetBits(n >> 1); 
} 

void copySetBits(unsigned &x, unsigned y, 
                 unsigned l, unsigned r) 
{ 
   // l and r must be between 1 to 32 
   // (assuming ints are stored using 
   //  32 bits) 
   if (l < 1 || r > 32) 
      return ; 
  
   // Travers in given range 
   for (int i=l; i<=r; i++) 
   { 
       // Find a mask (A number whose 
       // only set bit is at i'th position) 
       int mask = 1 << (i-1); 
  
       // If i'th bit is set in y, set i'th 
       // bit in x also. 
       if (y & mask) 
          x = x | mask; 
   } 
} 

// Sum of pairwise Hamming Distance
// C++ program to compute sum of pairwise bit differences 
// Sum of bit differences among all pairs

int sumBitDifferences(int arr[], int n) 
{ 
    int ans = 0;  // Initialize result 
  
    // traverse over all bits 
    for (int i = 0; i < 32; i++) 
    { 
        // count number of elements with i'th bit set 
        int count = 0; 
        for (int j = 0; j < n; j++) 
            if ( (arr[j] & (1 << i)) ) 
                count++; 
  
        // Add "count * (n - count) * 2" to the answer 
        ans += (count * (n - count) * 2); 
    } 
  
    return ans; 
} 