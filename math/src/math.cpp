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


/* Function to calculate x raised to the power y in O(logn)*/
int power(int x, unsigned int y) 
{ 
    int temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
} 

// Given three numbers a, b and c, we need to find (ab) % c

// The idea is based on below properties.

// Property 1:
// (m * n) % p has a very interesting property:
// (m * n) % p =((m % p) * (n % p)) % p

// Property 2:
// if b is even:
// (a ^ b) % c = ((a ^ b/2) * (a ^ b/2))%c : this suggests divide and conquer
// if b is odd:
// (a ^ b) % c = (a * (a ^( b-1))%c
//               ((a%c) * ((a ^( b-1))%c) ) % c

// Property 3:
// If we have to return the mod of a negative number x whose absolute value is less than y:
// then (x + y) % y will do the trick

// Recursive C program to compute modular power  

int exponentMod(int A, int B, int C) 
{ 
    // Base cases 
    if (A == 0) 
        return 0; 
    if (B == 0) 
        return 1; 
  
    // If B is even 
    long y; 
    if (B % 2 == 0) { 
        y = exponentMod(A, B / 2, C); 
        y = (y * y) % C; 
    } 
  
    // If B is odd 
    else { 
        y = A % C; 
        y = (y * exponentMod(A, B - 1, C) % C) % C; 
    } 
  
    return (int)((y + C) % C); 
} 

