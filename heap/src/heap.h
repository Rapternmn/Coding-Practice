#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A class for Max Heap
class MaxHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of max heap
    int heap_size; // Current number of elements in max heap
public:
    MaxHeap(int a[], int size); // Constructor
    void maxHeapify(int i);  //To maxHeapify subtree rooted with index i
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
 
    int extractMax();  // extracts root (maximum) element
    int getMax() { return harr[0]; } // Returns maximum
 
    // to replace root with new node x and heapify() new root
    void replaceMax(int x) { harr[0] = x;  maxHeapify(0); }
};
 

 
void heapify(int arr[], int n, int i) ;

void heapSort(int arr[], int n) ;


/// Median in a stream

