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