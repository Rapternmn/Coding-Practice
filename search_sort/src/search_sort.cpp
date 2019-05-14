#include "search_sort.h"


int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle 
        // itself
        if (arr[mid] == x)  
            return mid;
 
        // If element is smaller than mid, then 
        // it can only be present in left subarray
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not 
   // present in array
   return -1;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}
 
/* The main function that implements QuickSort
  arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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


// Search in a rotated Array

/* Function to get pivot. For array 3, 4, 5, 6, 1, 2 
   it returns 3 (index of 6) */
int findPivot(int arr[], int low, int high) 
{ 
    // base cases 
    if (high < low) return -1; 
    if (high == low) return low; 

    int mid = (low + high)/2; /*low + (high - low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1]) 
        return mid; 

    if (mid > low && arr[mid] < arr[mid - 1]) 
        return (mid-1); 

    if (arr[low] >= arr[mid]) 
        return findPivot(arr, low, mid-1); 

    return findPivot(arr, mid + 1, high); 
} 
  
/* Searches an element key in a pivoted 
   sorted array arr[] of size n */
int pivotedBinarySearch(int arr[], int n, int key) 
{ 
    int pivot = findPivot(arr, 0, n-1); 

    // If we didn't find a pivot,  
    // then array is not rotated at all 
    if (pivot == -1) 
        return binarySearch(arr, 0, n-1, key); 

    // If we found a pivot, then first compare with pivot 
    // and then search in two subarrays around pivot 
    if (arr[pivot] == key) 
        return pivot; 
      
    if (arr[0] <= key) 
        return binarySearch(arr, 0, pivot-1, key); 
      
    return binarySearch(arr, pivot+1, n-1, key); 
} 


// Function to find median of two sorted arrays 
double findMedianSortedArrays(int *a, int n,  int *b, int m) 
{ 
      
    int min_index = 0, max_index = n, i, j, median; 
      
    while (min_index <= max_index) 
    { 
        i = (min_index + max_index) / 2; 
        j = ((n + m + 1) / 2) - i; 
        
        // if i = n, it means that Elements from a[] in 
        // the second half is an empty set. and if j = 0, 
        // it means that Elements from b[] in the first 
        // half is an empty set. so it is necessary to 
        // check that, because we compare elements from 
        // these two groups.  
        // Searching on right 
        if (i < n && j > 0 && b[j - 1] > a[i])         
            min_index = i + 1; 
                  
        // if i = 0, it means that Elements from a[] in 
        // the first half is an empty set and if j = m, 
        // it means that Elements from b[] in the second 
        // half is an empty set. so it is necessary to 
        // check that, because we compare elements  
        // from these two groups. 
        // searching on left 
        else if (i > 0 && j < m && b[j] < a[i - 1])         
            max_index = i - 1; 
  
        // we have found the desired halves. 
        else
        { 
            // this condition happens when we don't have any 
            // elements in the first half from a[] so we 
            // returning the last element in b[] from  
            // the first half. 
            if (i == 0)             
                median = b[j - 1];             
              
            // and this condition happens when we don't 
            // have any elements in the first half from 
            // b[] so we returning the last element in  
            // a[] from the first half. 
            else if (j == 0)             
                median = a[i - 1];             
            else            
                median = maximum(a[i - 1], b[j - 1]);             
            break; 
        } 
    } 
      
    // calculating the median. 
    // If number of elements is odd there is  
    // one middle element. 
    if ((n + m) % 2 == 1) 
        return (double)median; 
          
    // Elements from a[] in the second half is an empty set.     
    if (i == n) 
        return (median+b[j]) / 2.0; 
          
    // Elements from b[] in the second half is an empty set. 
    if (j == m) 
        return (median + a[i]) / 2.0; 
      
    return (median + minimum(a[i], b[j])) / 2.0; 
} 


// Sort the input array, the array is assumed to 
// have values in {0, 1, 2} 
void sort012(int a[], int arr_size) 
{ 
    int lo = 0; 
    int hi = arr_size - 1; 
    int mid = 0; 
  
    while (mid <= hi) 
    { 
        switch (a[mid]) 
        { 
        case 0: 
            swap(&a[lo++], &a[mid++]); 
            break; 
        case 1: 
            mid++; 
            break; 
        case 2: 
            swap(&a[mid], &a[hi--]); 
            break; 
        } 
    } 
}

/* This function returns median of ar1[] and ar2[]. 
Assumptions in this function: Both ar1[] and ar2[] are sorted arrays 
Both have n elements */

int getMedian(int ar1[], 
              int ar2[], int n) 
{ 
    int i = 0; /* Current index of i/p array ar1[] */
    int j = 0; /* Current index of i/p array ar2[] */
    int count; 
    int m1 = -1, m2 = -1; 
      
    /* Since there are 2n elements,  
    median will be average of elements  
    at index n-1 and n in the array  
    obtained after merging ar1 and ar2 */
    for (count = 0; count <= n; count++) 
    { 
        /* Below is to handle case where  
           all elements of ar1[] are 
           smaller than smallest(or first) 
           element of ar2[]*/
        if (i == n) 
        { 
            m1 = m2; 
            m2 = ar2[0]; 
            break; 
        } 
  
        /*Below is to handle case where  
          all elements of ar2[] are 
          smaller than smallest(or first) 
          element of ar1[]*/
        else if (j == n) 
        { 
            m1 = m2; 
            m2 = ar1[0]; 
            break; 
        } 
  
        if (ar1[i] < ar2[j]) 
        { 
            /* Store the prev median */
            m1 = m2;  
            m2 = ar1[i]; 
            i++; 
        } 
        else
        { 
            /* Store the prev median */
            m1 = m2;  
            m2 = ar2[j]; 
            j++; 
        } 
    } 
  
    return (m1 + m2)/2; 
} 

/* This function returns median of ar1[] and ar2[].  
Assumption in this function:  
Both ar1[] and ar2[] are sorted arrays */
int getMedian(int ar1[], int ar2[], int n, int m)  
{  
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;  
    int m1 = -1, m2 = -1;  
  
    // Since there are (n+m) elements,  
    // There are following two cases 
    // if n+m is odd then the middle  
    //index is median i.e. (m+n)/2 
    if((m + n) % 2 == 1) { 
        for (count = 0; count <= (n + m)/2; count++) { 
            if(i != n && j != m){ 
            m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++]; 
            } 
            else if(i < n){ 
            m1 = ar1[i++]; 
            } 
            // for case when j<m, 
            else{ 
            m1 = ar1[j++]; 
            } 
        } 
        return m1; 
    } 
      
    // median will be average of elements  
    // at index ((m+n)/2 - 1) and (m+n)/2 
    // in the array obtained after merging ar1 and ar2 
    else { 
        for (count = 0; count <= (n + m)/2; count++) { 
            m2 = m1; 
            if(i != n && j != m){ 
            m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++]; 
            } 
            else if(i < n){ 
            m1 = ar1[i++]; 
            } 
            // for case when j<m, 
            else{ 
            m1 = ar1[j++]; 
            } 
        } 
        return (m1 + m2)/2; 
    } 
} 


  
// /* Driver program to test above function */
// int main()  
// {  
//     int ar1[] = {900};  
//     int ar2[] = {5, 8, 10, 20};  
  
//     int n1 = sizeof(ar1)/sizeof(ar1[0]);  
//     int n2 = sizeof(ar2)/sizeof(ar2[0]);  
//     printf("%d", getMedian(ar1, ar2, n1, n2));  
//     getchar();  
//     return 0;  
// }  
// // This code is uploaded by Pratil 



/* if x is present in arr[] then returns the index of 
   FIRST occurrence of x in arr[0..n-1], otherwise 
   returns -1 */
int first(int arr[], int low, int high, int x, int n) 
{ 
    if(high >= low) 
    { 
        int mid = low + (high - low)/2; 
        if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x) 
            return mid; 
        else if(x > arr[mid]) 
            return first(arr, (mid + 1), high, x, n); 
        else
            return first(arr, low, (mid -1), x, n); 
    } 
    return -1; 
} 
  
  
/* if x is present in arr[] then returns the index of 
   LAST occurrence of x in arr[0..n-1], otherwise 
   returns -1 */
int last(int arr[], int low, int high, int x, int n) 
{ 
    if (high >= low) 
    { 
        int mid = low + (high - low)/2; 
        if (( mid == n-1 || x < arr[mid+1]) && arr[mid] == x) 
            return mid; 
        else if (x < arr[mid]) 
            return last(arr, low, (mid -1), x, n); 
        else
            return last(arr, (mid + 1), high, x, n); 
    } 
    return -1; 
}

// Returns number of times x occurs in arr[0..n-1] 
int countOccurrences(int arr[], int n, int x) 
{ 
    int ind = binarySearch(arr, 0, n - 1, x); 
  
    // If element is not present 
    if (ind == -1) 
        return 0; 
  
    // Count elements on left side. 
    int count = 1; 
    int left = ind - 1; 
    while (left >= 0 && arr[left] == x) 
        count++, left--; 
  
    // Count elements on right side. 
    int right = ind + 1; 
    while (right < n && arr[right] == x) 
        count++, right++; 
  
    return count; 
} 