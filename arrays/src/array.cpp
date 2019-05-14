#include "array.h"

// Sort stuff

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// Standard partition process of QuickSort().  It considers the last
// element as pivot and moves all smaller element to left of it
// and greater elements to right
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

void quickSort(int A[], int si, int ei) 
{ 
    int pi;    /* Partitioning index */
    if(si < ei) 
    { 
        pi = partition(A, si, ei); 
        quickSort(A, si, pi - 1); 
        quickSort(A, pi + 1, ei); 
    } 
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

// Find subarray with given sum | Set 1 (Nonnegative Numbers)

int subArraySum(int arr[], int n, int sum)
{
    /* Initialize curr_sum as value of first element
       and starting point as 0 */
    int curr_sum = arr[0], start = 0, i;
 
    /* Add elements one by one to curr_sum and if the curr_sum exceeds the
       sum, then remove starting element */
    for (i = 1; i <= n; i++)
    {
        // If curr_sum exceeds the sum, then remove the starting elements
        while (curr_sum > sum && start < i-1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }
 
        // If curr_sum becomes equal to sum, then return true
        if (curr_sum == sum)
        {
            printf ("Sum found between indexes %d and %d", start, i-1);
            return 1;
        }
 
        // Add this element to curr_sum
        if (i < n)
          curr_sum = curr_sum + arr[i];
    }
 
    // If we reach here, then no subarray
    printf("No subarray found");
    return 0;
}

// This function returns k'th smallest element in arr[l..r] using
// QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, l, r);
 
        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left subarray
            return kthSmallest(arr, l, pos-1, k);
 
        // Else recur for right subarray
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
 
    // If k is more than number of elements in array
    return INT_MAX;
}

// An Inplace function to rotate a N x N matrix 
// by 90 degrees in anti-clockwise direction 
void rotateMatrix(int mat[][N]) 
{ 
    // Consider all squares one by one 
    for (int x = 0; x < N / 2; x++) 
    { 
        // Consider elements in group of 4 in  
        // current square 
        for (int y = x; y < N-x-1; y++) 
        { 
            // store current cell in temp variable 
            int temp = mat[x][y]; 
  
            // move values from right to top 
            mat[x][y] = mat[y][N-1-x]; 
  
            // move values from bottom to right 
            mat[y][N-1-x] = mat[N-1-x][N-1-y]; 
  
            // move values from left to bottom 
            mat[N-1-x][N-1-y] = mat[N-1-y][x]; 
  
            // assign temp to left 
            mat[N-1-y][x] = temp; 
        } 
    } 
} 


/* Function to find the candidate for Majority */
int findCandidate(int a[], int size) 
{ 
    int maj_index = 0, count = 1; 
    for (int i = 1; i < size; i++) 
    { 
        if (a[maj_index] == a[i]) 
            count++; 
        else
            count--; 
        if (count == 0) 
        { 
            maj_index = i; 
            count = 1; 
        } 
    } 
    return a[maj_index]; 
}

bool isMajority(int a[], int size, int cand) 
{ 
    int count = 0;

    for (int i = 0; i < size; i++)
        if (a[i] == cand)
            count++;
        
    if (count > size/2)
        return 1;
    else
        return 0;
} 

int appearsNBy3(int arr[], int n) 
{ 
    int count1 = 0, count2 = 0; 
    int first=INT_MAX    , second=INT_MAX  ; 
  
    for (int i = 0; i < n; i++) 
    { 
        // if this element is previously seen,  
        // increment count1. 
        if (first == arr[i]) 
            count1++; 
  
        // if this element is previously seen,  
        // increment count2. 
        else if (second == arr[i]) 
            count2++; 
      
        else if (count1 == 0) { 
            count1++; 
            first = arr[i]; 
        } 
  
        else if (count2 == 0) { 
            count2++; 
            second = arr[i]; 
        } 
  
        // if current element is different from 
        // both the previously seen variables,  
        // decrement both the counts. 
        else { 
            count1--; 
            count2--; 
        } 
    } 
  
    count1 = 0; 
    count2 = 0; 
  
    // Again traverse the array and find the 
    // actual counts. 
    for (int i = 0; i < n; i++) { 
        if (arr[i] == first) 
            count1++; 
  
        else if (arr[i] == second) 
            count2++; 
    } 
  
    if (count1 > n / 3) 
        return first; 
  
    if (count2 > n / 3) 
        return second; 
  
    return -1; 
} 
  
int main() 
{ 
    int arr[] = { 1, 2, 3, 1, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << appearsNBy3(arr, n) << endl; 
    return 0; 
} 

// Maximum Area Histogram

// The main function to find the maximum rectangular  
// area under given histogram with n bars 
int getMaxArea(int hist[], int n) 
{ 
    // Create an empty stack. The stack holds indexes  
    // of hist[] array. The bars stored in stack are  
    // always in increasing order of their heights. 
    stack<int> s; 
  
    int max_area = 0; // Initalize max area 
    int tp;  // To store top of stack 
    int area_with_top; // To store area with top bar 
                       // as the smallest bar 
  
    // Run through all bars of given histogram 
    int i = 0; 
    while (i < n) 
    { 
        // If this bar is higher than the bar on top  
        // stack, push it to stack 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        // If this bar is lower than top of stack,  
        // then calculate area of rectangle with stack  
        // top as the smallest (or minimum height) bar.  
        // 'i' is 'right index' for the top and element  
        // before top in stack is 'left index' 
        else
        { 
            tp = s.top();  // store the top index 
            s.pop();  // pop the top 
  
            // Calculate the area with hist[tp] stack  
            // as smallest bar 
            area_with_top = hist[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 
  
            // update max area, if needed 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
} 


// Sudoku Back Tracking


/* Takes a partially filled-in grid and attempts to assign values to 
  all unassigned locations in such a way to meet the requirements 
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(int grid[N][N]) 
{ 
    int row, col; 
  
    // If there is no unassigned location, we are done 
    if (!FindUnassignedLocation(grid, row, col)) 
       return true; // success! 
  
    // consider digits 1 to 9 
    for (int num = 1; num <= 9; num++) 
    { 
        // if looks promising 
        if (isSafe(grid, row, col, num)) 
        { 
            // make tentative assignment 
            grid[row][col] = num; 
  
            // return, if success, yay! 
            if (SolveSudoku(grid)) 
                return true; 
  
            // failure, unmake & try again 
            grid[row][col] = UNASSIGNED; 
        } 
    } 
    return false; // this triggers backtracking 
} 
  
/* Searches the grid to find an entry that is still unassigned. If 
   found, the reference parameters row, col will be set the location 
   that is unassigned, and true is returned. If no unassigned entries 
   remain, false is returned. */
bool FindUnassignedLocation(int grid[N][N], int &row, int &col) 
{ 
    for (row = 0; row < N; row++) 
        for (col = 0; col < N; col++) 
            if (grid[row][col] == UNASSIGNED) 
                return true; 
    return false; 
} 
  
/* Returns a boolean which indicates whether an assigned entry 
   in the specified row matches the given number. */
bool UsedInRow(int grid[N][N], int row, int num) 
{ 
    for (int col = 0; col < N; col++) 
        if (grid[row][col] == num) 
            return true; 
    return false; 
} 
  
/* Returns a boolean which indicates whether an assigned entry 
   in the specified column matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num) 
{ 
    for (int row = 0; row < N; row++) 
        if (grid[row][col] == num) 
            return true; 
    return false; 
} 
  
/* Returns a boolean which indicates whether an assigned entry 
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) 
{ 
    for (int row = 0; row < 3; row++) 
        for (int col = 0; col < 3; col++) 
            if (grid[row+boxStartRow][col+boxStartCol] == num) 
                return true; 
    return false; 
} 
  
/* Returns a boolean which indicates whether it will be legal to assign 
   num to the given row,col location. */
bool isSafe(int grid[N][N], int row, int col, int num) 
{ 
    /* Check if 'num' is not already placed in current row, 
       current column and current 3x3 box */
    return !UsedInRow(grid, row, num) && 
           !UsedInCol(grid, col, num) && 
           !UsedInBox(grid, row - row%3 , col - col%3, num); 
} 

// Find the length of largest subarray with 0 sum

// Returns Length of the required subarray 
int maxLen(int arr[], int n) 
{ 
    // Map to store the previous sums 
    unordered_map<int, int> presum; 
  
    int sum = 0;        // Initialize the sum of elements 
    int max_len = 0;    // Initialize result 
  
    // Traverse through the given array 
    for(int i=0; i<n; i++) 
    { 
        // Add current element to sum 
        sum += arr[i]; 

        if (arr[i]==0 && max_len==0) 
            max_len = 1; 
        if (sum == 0) 
            max_len = i+1; 

        // Look for this sum in Hash table 
        if(presum.find(sum) != presum.end()) 
        { 
            // If this sum is seen before, then update max_len 
            max_len = max(max_len, i-presum[sum]); 
        } 
        else
        { 
            // Else insert this sum with index in hash table 
            presum[sum] = i; 
        } 
    }

    return max_len; 
}

bool isSubset(int arr1[], int arr2[], int m, int n) 
{ 
    int i = 0; 
    
    quickSort(arr1, 0, m-1); 
    for (i=0; i<n; i++) 
    { 
        if (binarySearch(arr1, 0, m-1, arr2[i]) == -1) 
           return 0; 
    } 
      
    /* If we reach here then all elements of arr2[]  
      are present in arr1[] */
    return 1; 
} 

// Google 

// This function sorts arr[0..n-1] in wave form, i.e.,  
// arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5].. 
void sortInWave(int arr[], int n) 
{ 
    // Sort the input array 
    sort(arr, arr+n); 
  
    // Swap adjacent elements 
    for (int i=0; i<n-1; i += 2) 
        swap(&arr[i], &arr[i+1]); 
} 

// O(n) solution

// This function sorts arr[0..n-1] in wave form, i.e., 
// arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5] .... 

void sortInWave(int arr[], int n) 
{ 
    // Traverse all even elements 
    for (int i = 0; i < n; i+=2) 
    { 
        // If current even element is smaller than previous 
        if (i>0 && arr[i-1] > arr[i] ) 
            swap(&arr[i], &arr[i-1]); 
  
        // If current even element is smaller than next 
        if (i<n-1 && arr[i] < arr[i+1] ) 
            swap(&arr[i], &arr[i + 1]); 
    } 
} 

// An interval has start time and end time 
struct Interval 
{ 
    int start, end; 
}; 
  
// Compares two intervals according to their staring time. 
// This is needed for sorting the intervals using library 
// function std::sort(). See http://goo.gl/iGspV 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
} 

// The main function that takes a set of intervals, merges 
// overlapping intervals and prints the result 
void mergeIntervals(Interval arr[], int n) 
{ 
    // Test if the given set has at least one interval 
    if (n <= 0) 
        return; 
  
    // Create an empty stack of intervals 
    stack<Interval> s; 
  
    // sort the intervals in increasing order of start time 
    sort(arr, arr+n, compareInterval); 
  
    // push the first interval to stack 
    s.push(arr[0]);
  
    // Start from the next interval and merge if necessary 
    for (int i = 1 ; i < n; i++) 
    { 
        // get interval from stack top 
        Interval top = s.top(); 
  
        // if current interval is not overlapping with stack top, 
        // push it to the stack 
        if (top.end < arr[i].start) 
            s.push(arr[i]); 
  
        // Otherwise update the ending time of top if ending of current 
        // interval is more 
        else if (top.end < arr[i].end) 
        { 
            top.end = arr[i].end; 
            s.pop(); 
            s.push(top); 
        } 
    } 
  
    // Print contents of stack 
    cout << "\n The Merged Intervals are: "; 
    while (!s.empty()) 
    { 
        Interval t = s.top(); 
        cout << "[" << t.start << "," << t.end << "] "; 
        s.pop(); 
    } 
    return; 
} 

/* For a given array arr[], returns the maximum j – i such that 
    arr[j] > arr[i] */
int maxIndexDiff(int arr[], int n) 
{ 
    int maxDiff; 
    int i, j; 
  
    int *LMin = (int *)malloc(sizeof(int)*n); 
    int *RMax = (int *)malloc(sizeof(int)*n); 
  
   /* Construct LMin[] such that LMin[i] stores the minimum value 
       from (arr[0], arr[1], ... arr[i]) */
    LMin[0] = arr[0]; 
    for (i = 1; i < n; ++i) 
        LMin[i] = min(arr[i], LMin[i-1]); 
  
    /* Construct RMax[] such that RMax[j] stores the maximum value 
       from (arr[j], arr[j+1], ..arr[n-1]) */
    RMax[n-1] = arr[n-1]; 
    for (j = n-2; j >= 0; --j) 
        RMax[j] = max(arr[j], RMax[j+1]); 
  
    /* Traverse both arrays from left to right to find optimum j - i 
        This process is similar to merge() of MergeSort */
    i = 0, j = 0, maxDiff = -1; 
    while (j < n && i < n) 
    { 
        if (LMin[i] < RMax[j]) 
        { 
            maxDiff = max(maxDiff, j-i); 
            j = j + 1; 
        } 
        else
            i = i+1; 
    } 
  
    return maxDiff; 
} 