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


// Largest Sum Contiguous Subarray, Kadane Algo

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;
 
	for (int i = 0; i < size; i++)
	{
		max_ending_here = max_ending_here + a[i];

		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;
 
		if (max_ending_here < 0)
			max_ending_here = 0;
	}

	return max_so_far;
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


/*

Input : agbdba

Output : bdb

	a    g    b    d    b     a

a   1    1    1    1    1     1


g        1    1         


b             1    1         


d                  1     1


b                        1    1


a                             1


*/

int longestPalSubstr( char *str )
{
	int n = strlen( str );

	bool table[n][n]; 
	memset(table, 0, sizeof(table)); 

	for(int i = 0; i<n;i++)
	  table[i][i] = true;

	int start = 0;
	int max_len = 1;

	for(int i = 0;i < n-1;i++)
	{
		if(str[i] == str[i+1])
		{
			table[i][i+1] = true;
			start = i;
			max_len = 2;
		}
	}

	// For len > 3

	for (int k = 3; k <= n; ++k) 
	{ 
		for(int i = 0;i<n-k+1;i++)
		{
			j = i+k-1 ; // end index

			if(table[i+1][j-1] &&  str[i] == str[j])
			{
				table[i][j] = true;
				if (k > maxLength) 
				{
					start = i ;
					max_len = k ;
				}
			}
		}
	}

	printf("Longest palindrome substring is: "); 
    printSubStr( str, start, start + max_len - 1 ); 
  
    return max_len; // return length of LPS 
}



/// Maximum size square sub-matrix with all 1s


/*

Matrix : Mat[M][M]


0   0   1   1   1

1   0   1   1   1

0   1   1   1   1

1   0   1   1   1


DP Mat : Mat[M+1][N+1]

	0   1   2   3   4   5

0   0   0   0   0   0   0

1   0   0   0   1   1   1

2   0   1   0   1   2   2

3   0   0   1   1   2   3

4   0   1   0   1   2   3

*/

void printMaxSubSquare(bool M[R][C]) 
{ 
  int i,j; 
  int S[R][C]; 
  int max_of_s, max_i, max_j;  
	
  /* Set first column of S[][]*/
  for(i = 0; i < R; i++) 
	  S[i][0] = M[i][0]; 
	
  /* Set first row of S[][]*/ 
  for(j = 0; j < C; j++) 
	  S[0][j] = M[0][j]; 
		
  /* Construct other entries of S[][]*/
  for(i = 1; i < R; i++) 
  { 
	  for(j = 1; j < C; j++) 
	  { 
	  if(M[i][j] == 1)  
		  S[i][j] = min(S[i][j-1], S[i-1][j],  
						  S[i-1][j-1]) + 1; 
	  else
		  S[i][j] = 0; 
	  }  
  }  
	
  /* Find the maximum entry, and indexes of maximum entry  
	  in S[][] */
  max_of_s = S[0][0]; max_i = 0; max_j = 0; 
  for(i = 0; i < R; i++) 
  { 
	  for(j = 0; j < C; j++) 
	  { 
	  if(max_of_s < S[i][j]) 
	  { 
		  max_of_s = S[i][j]; 
		  max_i = i;  
		  max_j = j; 
	  }     
	  }                 
  }     
	
  printf("Maximum size sub-matrix is: \n"); 
  for(i = max_i; i > max_i - max_of_s; i--) 
  { 
	  for(j = max_j; j > max_j - max_of_s; j--) 
	  { 
	  printf("%d ", M[i][j]); 
	  }  
	  printf("\n"); 
  } 

}


// Max Size Rectangle :

// Returns area of the largest rectangle with all 1s in A[][] 
int maxRectangle(int A[][C]) 
{ 
	// Calculate area for first row and initialize it as 
	// result 
	int result = maxHist(A[0]); 
  
	// iterate over row to find maximum rectangular area 
	// considering each row as histogram 
	for (int i = 1; i < R; i++) 
	{ 
  
		for (int j = 0; j < C; j++) 
  
			// if A[i][j] is 1 then add A[i -1][j] 
			if (A[i][j]) A[i][j] += A[i - 1][j]; 
  
  
		// Update result if area with current row (as last row) 
		// of rectangle) is more 
		result = max(result, maxHist(A[i])); 
	} 
  
	return result; 
} 

/* Returns the product of max product subarray.
   Assumes that the given array always has a subarray 
   with product more than 1 */
int maxSubarrayProduct(int arr[], int n) 
{ 
	// max positive product ending at the current position 
	int max_ending_here = 1; 
  
	// min negative product ending at the current position 
	int min_ending_here = 1; 
  
	// Initialize overall max product 
	int max_so_far = 1; 
  
	/* Traverse through the array. Following values are 
	   maintained after the i'th iteration: 
	   max_ending_here is always 1 or some positive product 
					   ending with arr[i] 
	   min_ending_here is always 1 or some negative product  
					   ending with arr[i] */
	for (int i = 0; i < n; i++) 
	{ 
		/* If this element is positive, update max_ending_here.  
		   Update min_ending_here only if min_ending_here is  
		   negative */
		if (arr[i] > 0) 
		{ 
			max_ending_here = max_ending_here*arr[i]; 
			min_ending_here = min (min_ending_here * arr[i], 1); 
		} 
  
		/* If this element is 0, then the maximum product  
		   cannot end here, make both max_ending_here and  
		   min_ending_here 0 
		   Assumption: Output is alway greater than or equal  
					   to 1. */
		else if (arr[i] == 0) 
		{ 
			max_ending_here = 1; 
			min_ending_here = 1; 
		} 
  
		/* If element is negative. This is tricky 
		   max_ending_here can either be 1 or positive.  
		   min_ending_here can either be 1 or negative. 
		   next min_ending_here will always be prev.  
		   max_ending_here * arr[i] next max_ending_here 
		   will be 1 if prev min_ending_here is 1, otherwise  
		   next max_ending_here will be prev min_ending_here * 
		   arr[i] */
		else
		{ 
			int temp = max_ending_here; 
			max_ending_here = max (min_ending_here * arr[i], 1); 
			min_ending_here = temp * arr[i]; 
		} 
  
		// update max_so_far, if needed 
		if (max_so_far <  max_ending_here) 
		  max_so_far  =  max_ending_here; 
	} 
  
	return max_so_far; 
} 


// 	F(i, j)  represents the maximum value the user can collect from 
//          i'th coin to j'th coin.

// 	F(i, j)  = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
//                Vj + min(F(i+1, j-1), F(i, j-2) )) 
// 	Base Cases
//     F(i, j)  = Vi           If j == i
//     F(i, j)  = max(Vi, Vj)  If j == i+1

// Returns optimal value possible that a player can 
// collect from an array of coins of size n. Note 
// than n must be even 
int optimalStrategyOfGame(int* arr, int n) 
{ 
    // Create a table to store solutions of subproblems 
    int table[n][n]; 
  
    // Fill table using above recursive formula. Note  
    // that the table is filled in diagonal fashion (similar 
    // to http:// goo.gl/PQqoS), from diagonal elements to 
    // table[0][n-1] which is the result. 
    for (int gap = 0; gap < n; ++gap) { 
        for (int i = 0, j = gap; j < n; ++i, ++j) { 
  
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and 
            // z is F(i, j-2) in above recursive formula 
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); 
        } 
    } 
  
    return table[0][n - 1]; 
} 

// Returns count of possible paths to reach cell at 
// row number m and column  number n from the topmost  
// leftmost cell (cell at 1, 1) 
int numberOfPaths(int m, int n) 
{ 
    // Create a 2D table to store results of subproblems 
    int count[m][n]; 
  
    // Count of paths to reach any cell in first column is 1 
    for (int i = 0; i < m; i++) 
        count[i][0] = 1; 
  
    // Count of paths to reach any cell in first column is 1 
    for (int j = 0; j < n; j++) 
        count[0][j] = 1; 
  
    // Calculate count of paths for other cells in  
    // bottom-up manner using the recursive solution 
    for (int i = 1; i < m; i++) 
    { 
        for (int j = 1; j < n; j++) 
  
            // By uncommenting the last part the code calculatest he total 
            // possible paths if the diagonal Movements are allowed 
            count[i][j] = count[i-1][j] + count[i][j-1]; //+ count[i-1][j-1]; 
  
    } 
    return count[m-1][n-1]; 
} 