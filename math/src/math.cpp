#include "math.h"

//Fibonacci Series using Recursion 

int fib_recur(int n) 
{ 
   if (n <= 1) 
      return n; 
   return fib(n-1) + fib(n-2); 
}

// DP

int fib_dp(int n) 
{
    int f[n+2];   // 1 extra to handle case, n = 0 
    int i; 

    f[0] = 0; 
    f[1] = 1; 
  
    for (i = 2; i <= n; i++) 
        f[i] = f[i-1] + f[i-2]; 

    return f[n]; 
} 


int fib_space_optimized(int n) 
{ 
    int a = 0, b = 1, c, i; 

    if( n == 0) 
        return a; 

    for (i = 2; i <= n; i++) 
    { 
        c = a + b; 
        a = b; 
        b = c; 
    } 

    return b; 
} 

void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
} 

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int generalizedGCD(int num, int* arr)    // GCD of an array
{
    // WRITE YOUR CODE HERE
    
    int res = arr[0];
    
    for(int i = 1;i< num;i++)
    {
        res = gcd(arr[i],res);
    }
    
    return res;
}
