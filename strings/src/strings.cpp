#include "strings.h"

void swap(char *a,char *b) 
{ 
    if( *a == *b ) 
        return; 
    *a^=*b; 
    *b^=*a; 
    *a^=*b; 
} 

void rev(string& s,int l,int r) 
{ 
    while(l<r) 
        swap(&s[l++],&s[r--]); 
} 

int bsearch (string& s,int l,int r,int key) 
{ 
    int index = -1; 
    while(l<=r) 
    { 
        int mid = l+(r-l)/2; 
        if(s[mid]<=key) 
            r=mid-1; 
        else
        { 
            l=mid+1; 
            if(index = -1 || s[index]<=s[mid]) 
                index = mid; 
        } 
    } 
return index; 
} 

/*

Algorithm:
1) Declare a character stack S.
2) Now traverse the expression string exp.
    a) If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
    b) If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack 
      and if the popped character is the matching starting bracket then fine else parenthesis 
      are not balanced.
3) After complete traversal, if there is some starting bracket left in stack then “not balanced”

*/

// function to check if paranthesis are balanced
bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;
 
    // Traversing the Expression
    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }
 
        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
           return false;
 
        switch (expr[i])
        {
        case ')':
 
            // Store the top element in a
            x = s.top();
            s.pop();
            if (x=='{' || x=='[')
                return false;
            break;
 
        case '}':
 
            // Store the top element in b
            x = s.top();
            s.pop();
            if (x=='(' || x=='[')
                return false;
            break;
 
        case ']':
 
            // Store the top element in c
            x = s.top();
            s.pop();
            if (x =='(' || x == '{')
                return false;
            break;
        }
    }
 
    // Check Empty Stack
    return (s.empty());
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

