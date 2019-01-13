#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
void printPrevSmaller(int arr[], int n) ;

/* Program to implement a stack using  
two queue */

class Stack 
{  
    // Two inbuilt queues 
    queue<int> q1, q2; 
      
    // To maintain current number of 
    // elements 
    int curr_size; 
  
    public: 
    Stack() 
    { 
        curr_size = 0; 
    } 
  
    void push(int x) ;
  
    void pop()
    { 
        // if no elements are there in q1  
        if (q1.empty()) 
            return ; 
        q1.pop(); 
        curr_size--; 
    } 
  
    int top() 
    { 
        if (q1.empty()) 
            return -1; 
        return q1.front(); 
    } 
  
    int size() 
    { 
        return curr_size; 
    } 
}; 


// CPP program to implement Queue using 
// two stacks with costly enQueue() 

struct Queue { 
    stack<int> s1, s2; 
  
    void enQueue(int x) 
    { 
        // Move all elements from s1 to s2 
        while (!s1.empty()) { 
            s2.push(s1.top()); 
            s1.pop(); 
        } 
  
        // Push item into s1 
        s1.push(x); 
  
        // Push everything back to s1 
        while (!s2.empty()) { 
            s1.push(s2.top()); 
            s2.pop(); 
        } 
    } 
  
    // Dequeue an item from the queue 
    int deQueue() 
    { 
        // if first stack is empty 
        if (s1.empty()) { 
            cout << "Q is Empty"; 
            exit(0); 
        } 
  
        // Return top of s1 
        int x = s1.top(); 
        s1.pop(); 
        return x; 
    } 
}; 


struct MyStack ;

// A stack based efficient method to calculate 
// stock span values 
void calculateSpan(int price[], int n, int S[]) ;

// Function to find precedence of  
// operators. 
int precedence(char op) ;

// Function to perform arithmetic operations. 
int applyOp(int a, int b, char op) ;

// Function that returns value of 
// expression after evaluation. 
int evaluate(string tokens) ;