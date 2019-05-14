#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int lis( int arr[], int n ) ;

int lcs( char *X, char *Y, int m, int n );

int maxSubArraySum(int a[], int size);

int editDistDP(string str1, string str2, int m, int n);

int minCost(int cost[R][C], int m, int n) ;

int count_coin( int S[], int m, int n );

int knapSack(int W, int wt[], int val[], int n);

int longestPalSubstr( char *str ) ;

// Max Size Square :

void printMaxSubSquare(bool M[R][C])  ;

// Max Size rectangle :

// Returns area of the largest rectangle with all 1s in A[][] 
int maxRectangle(int A[][C]) ;

int maxSubarrayProduct(int arr[], int n) ;

// Optimal Strategy to win game

int optimalStrategyOfGame(int* arr, int n) ;

// Google 

// Returns count of possible paths to reach cell at 
// row number m and column  number n from the topmost  
// leftmost cell (cell at 1, 1) 
int numberOfPaths(int m, int n) ;