#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b);

int partition(int arr[], int l, int r);

void quickSort(int A[], int si, int ei) ;

// Largest Sum Contiguous Subarray
// Kadane's Algorithm

int maxSubArraySum(int a[], int size) ;

int subArraySum(int arr[], int n, int sum) ;

// Kth smallest 

int kthSmallest(int arr[], int l, int r, int k);

void rotateMatrix(int mat[][N]) ;

// Find Majority Element // Moore’s Voting algorithm.

int findCandidate(int a[], int size) ;

bool isMajority(int a[], int size, int cand) ;

// Maximum Area Histogram

int getMaxArea(int hist[], int n) ;

// Sudoku Back Tracking

bool SolveSudoku(int grid[N][N]) ;

bool FindUnassignedLocation(int grid[N][N], int &row, int &col) ;

bool UsedInRow(int grid[N][N], int row, int num) ;

bool UsedInCol(int grid[N][N], int col, int num) ;

bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) ;

bool isSafe(int grid[N][N], int row, int col, int num) ;

// Find the length of largest subarray with 0 sum

// Returns Length of the required subarray 

int maxLen(int arr[], int n) ;

// C program to find whether an array 
// is subset of another array 
// (Use Sorting and Binary Search)

bool isSubset(int arr1[], int arr2[], int m, int n) ;

// Google

void sortInWave(int arr[], int n) ;

void mergeIntervals(Interval arr[], int n) ;

int maxIndexDiff(int arr[], int n) ;