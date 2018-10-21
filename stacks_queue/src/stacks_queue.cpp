#include "stacks_queue.h"

void printPrevSmaller(int arr[], int n) 
{ 
    // Create an empty stack 
    stack<int> S; 
  
    // Traverse all array elements 
    for (int i=0; i<n; i++) 
    { 
        // Keep removing top element from S while the top 
        // element is greater than or equal to arr[i] 
        while (!S.empty() && S.top() >= arr[i]) 
            S.pop(); 
  
        // If all elements in S were greater than arr[i] 
        if (S.empty()) 
            cout << "_, "; 
        else  //Else print the nearest smaller element 
            cout << S.top() << ", "; 
  
        // Push this element 
        S.push(arr[i]); 
    } 
} 