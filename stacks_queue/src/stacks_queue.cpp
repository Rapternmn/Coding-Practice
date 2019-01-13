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


void Stack::push(int x)
{
    curr_size++; 
    // Push x first in empty q2 
    q2.push(x); 
    // Push all the remaining  
    // elements in q1 to q2.  
    while (!q1.empty()) 
    { 
        q2.push(q1.front()); 
        q1.pop(); 
    }
    // swap the names of two queues 
    queue<int> q = q1; 
    q1 = q2; 
    q2 = q; 
}


// A user defined stack that supports getMin() in 
// addition to push() and pop() 
struct MyStack 
{ 
    stack<int> s; 
    int minEle; 
  
    // Prints minimum element of MyStack 
    void getMin() 
    { 
        if (s.empty()) 
            cout << "Stack is empty\n"; 
  
        // variable minEle stores the minimum element 
        // in the stack. 
        else
            cout <<"Minimum Element in the stack is: "
                 << minEle << "\n"; 
    } 
  
    // Prints top element of MyStack 
    void peek() 
    { 
        if (s.empty()) 
        { 
            cout << "Stack is empty "; 
            return; 
        } 
  
        int t = s.top(); // Top element. 
  
        cout << "Top Most Element is: "; 
  
        // If t < minEle means minEle stores 
        // value of t. 
        (t < minEle)? cout << minEle: cout << t; 
    } 
  
    // Remove the top element from MyStack 
    void pop() 
    { 
        if (s.empty()) 
        { 
            cout << "Stack is empty\n"; 
            return; 
        } 
  
        cout << "Top Most Element Removed: "; 
        int t = s.top(); 
        s.pop(); 
  
        // Minimum will change as the minimum element 
        // of the stack is being removed. 
        if (t < minEle) 
        { 
            cout << minEle << "\n"; 
            minEle = 2*minEle - t; 
        } 
  
        else
            cout << t << "\n"; 
    } 
  
    // Removes top element from MyStack 
    void push(int x) 
    { 
        // Insert new number into the stack 
        if (s.empty()) 
        { 
            minEle = x; 
            s.push(x); 
            cout <<  "Number Inserted: " << x << "\n"; 
            return; 
        } 
  
        // If new number is less than minEle 
        if (x < minEle) 
        { 
            s.push(2*x - minEle); 
            minEle = x; 
        } 
  
        else
           s.push(x); 
  
        cout <<  "Number Inserted: " << x << "\n"; 
    } 
}; 

// A stack based efficient method to calculate 
// stock span values 
void calculateSpan(int price[], int n, int S[]) 
{ 
   // Create a stack and push index of first 
   // element to it 
   stack<int> st; 
   st.push(0); 
  
   // Span value of first element is always 1 
   S[0] = 1; 
  
   // Calculate span values for rest of the elements 
   for (int i = 1; i < n; i++) 
   { 
      // Pop elements from stack while stack is not  
      // empty and top of stack is smaller than  
      // price[i] 
      while (!st.empty() && price[st.top()] <= price[i]) 
         st.pop(); 
  
      // If stack becomes empty, then price[i] is 
      // greater than all elements on left of it, 
      // i.e., price[0], price[1],..price[i-1].  Else 
      // price[i] is greater than elements after  
      // top of stack 
      S[i] = (st.empty())? (i + 1) : (i - st.top()); 
  
      // Push this element to stack 
      st.push(i); 
   } 
} 



// Function to find precedence of  
// operators. 
int precedence(char op){ 
    if(op == '+'||op == '-') 
    return 1; 
    if(op == '*'||op == '/') 
    return 2; 
    return 0; 
} 
  
// Function to perform arithmetic operations. 
int applyOp(int a, int b, char op){ 
    switch(op){ 
        case '+': return a + b; 
        case '-': return a - b; 
        case '*': return a * b; 
        case '/': return a / b; 
    } 
} 
  
// Function that returns value of 
// expression after evaluation. 
int evaluate(string tokens){ 
    int i; 
      
    // stack to store integer values. 
    stack <int> values; 
      
    // stack to store operators. 
    stack <char> ops; 
      
    for(i = 0; i < tokens.length(); i++){ 
          
        // Current token is a whitespace, 
        // skip it. 
        if(tokens[i] == ' ') 
            continue; 
          
        // Current token is an opening  
        // brace, push it to 'ops' 
        else if(tokens[i] == '('){ 
            ops.push(tokens[i]); 
        } 
          
        // Current token is a number, push  
        // it to stack for numbers. 
        else if(isdigit(tokens[i])){ 
            int val = 0; 
              
            // There may be more than one 
            // digits in number. 
            while(i < tokens.length() &&  
                        isdigit(tokens[i])) 
            { 
                val = (val*10) + (tokens[i]-'0'); 
                i++; 
            } 
              
            values.push(val); 
        } 
          
        // Closing brace encountered, solve  
        // entire brace. 
        else if(tokens[i] == ')') 
        { 
            while(!ops.empty() && ops.top() != '(') 
            { 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                  
                values.push(applyOp(val1, val2, op)); 
            } 
              
            // pop opening brace. 
            ops.pop(); 
        } 
          
        // Current token is an operator. 
        else
        { 
            // While top of 'ops' has same or greater  
            // precedence to current token, which 
            // is an operator. Apply operator on top  
            // of 'ops' to top two elements in values stack. 
            while(!ops.empty() && precedence(ops.top()) 
                                >= precedence(tokens[i])){ 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                  
                values.push(applyOp(val1, val2, op)); 
            } 
              
            // Push current token to 'ops'. 
            ops.push(tokens[i]); 
        } 
    } 
      
    // Entire expression has been parsed at this 
    // point, apply remaining ops to remaining 
    // values. 
    while(!ops.empty()){ 
        int val2 = values.top(); 
        values.pop(); 
                  
        int val1 = values.top(); 
        values.pop(); 
                  
        char op = ops.top(); 
        ops.pop(); 
                  
        values.push(applyOp(val1, val2, op)); 
    } 
      
    // Top of 'values' contains result, return it. 
    return values.top(); 
} 