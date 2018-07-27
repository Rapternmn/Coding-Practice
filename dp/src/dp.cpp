#include "dp.h"

int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );
 
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    /* Free memory to avoid memory leak */
    free(lis);
 
    return max;
}

// LCS

/*

Seq 1 : ABCDGH

Seq 2 : AEDFHR

        A   B   C   D   G   H

    0   0   0   0   0   0   0   

A   0   1   1   1   1   1   1

E   0   1   1   1   1   1   1

D   0   1   1   1   2   2   2

F   0   1   1   1   2   2   2

H   0   1   1   1   2   2   3

R   0   1   1   1   2   2   3

if (L1[i] == L2[j])

    LCS[i][j] = LCS[i-1][j-1] + 1

else
    
    LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1])

*/

int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}


// Edit distance

/*

Seq 1 : sunday

Seq 2 : saturday

    
        s   u   n   d   a   y

    0   1   2   3   4   5   6

s   1   0   1   2   3   4   5

a   2   1   1   2   3   3   4

t   3   2   2   2   3   4   5   

u   4   3   2   3   3   4   5

r   5   4   3   3   4   4   5

d   6   5   4   4   3   4   5

a   7   6   5   5   4   3   4

y   8   7   6   6   5   4   3


if (str1[i-1] == str2[j-1])

    dp[i][j] = dp[i-1][j-1];

else
    dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                       dp[i-1][j],  // Remove
                       dp[i-1][j-1]); // Replace

*/

int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m+1][n+1];
 
    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            // If the last character is different, consider all
            // possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }
 
    return dp[m][n];
}

// Min cost path

/*

Optimal Substructure

minCost(m, n) = min (minCost(m-1, n-1), minCost(m-1, n), minCost(m, n-1)) + cost[m][n]

Mat :

        1   2   3   

        4   8   2   

        1   5   3


Cost Mat

        
        1   3   6

        5   9   5  

        6   10  8

*/

int minCost(int cost[R][C], int m, int n)
{
     int i, j;
 
     // Instead of following line, we can use int tc[m+1][n+1] or 
     // dynamically allocate memoery to save space. The following line is
     // used to keep te program simple and make it working on all compilers.
     int tc[R][C];  
 
     tc[0][0] = cost[0][0];
 
     /* Initialize first column of total cost(tc) array */
     for (i = 1; i <= m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];
 
     /* Initialize first row of tc array */
     for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];
 
     /* Construct rest of the tc array */
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i-1][j-1], 
                           tc[i-1][j], 
                           tc[i][j-1]) + cost[i][j];
 
     return tc[m][n];
}

// Coin change path

/*



*/

// C program for coin change problem.
 
int count_coin( int S[], int m, int n )
{
    int i, j, x, y;
 
    // We need n+1 rows as the table is constructed 
    // in bottom up manner using the base case 0
    // value case (n = 0)
    int table[n+1][m];
    
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table entries in bottom 
    // up manner  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}


// 0-1 Knapsnack problem

/*

Total wt = 7

wt []  = [1,3,4,5]

val = [1,4,5,7]

Mat :

val     wt      0   1   2   3   4   5   6   7    -> wt

1       1       0   1   1   1   1   1   1   1    -> val

4       3       0   1   1   4   5   5   5   5    -> val

5       4       0   1   1   4   5   6   6   9    -> val

7       5       0   1   1   4   5   7   8   9    -> val


if (j < wt[i] )

    T[i][j] = T[i-1][j] 

else
    
    T[i][j] = max( val[i] +  T[i-1][j-wt[i]] , T[i-1][j] )

*/

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}