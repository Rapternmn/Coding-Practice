#include "misc.h"


int dictionaryContains(string &word) 
{ 
    string dictionary[] = {"mobile","samsung","sam","sung", 
                            "man","mango", "icecream","and", 
                            "go","i","love","ice","cream"}; 
    int n = sizeof(dictionary)/sizeof(dictionary[0]); 
    for (int i = 0; i < n; i++) 
        if (dictionary[i].compare(word) == 0) 
            return true; 
    return false; 
} 
  
// Prints all possible word breaks of given string 
void wordBreak(string str) 
{ 
    // last argument is prefix 
    wordBreakUtil(str, str.size(), ""); 
} 
  
// result store the current prefix with spaces 
// between words 
void wordBreakUtil(string str, int n, string result) 
{ 
    //Process all prefixes one by one 
    for (int i=1; i<=n; i++) 
    { 
        //extract substring from 0 to i in prefix 
        string prefix = str.substr(0, i); 
  
        // if dictionary conatins this prefix, then 
        // we check for remaining string. Otherwise 
        // we ignore this prefix (there is no else for 
        // this if) and try next 
        if (dictionaryContains(prefix)) 
        { 
            // if no more elements are there, print it 
            if (i == n) 
            { 
                // add this element to previous prefix 
                result += prefix; 
                cout << result << endl; //print result 
                return; 
            } 
            wordBreakUtil(str.substr(i, n-i), n-i, result + prefix + " "); 
        } 
    }      //end for 
}//end function 



// Returns number of pairs in arr[0..n-1] with sum equal 
// to 'sum' 
int getPairsCount(int arr[], int n, int sum) 
{ 
    unordered_map<int, int> m; 
  
    // Store counts of all elements in map m 
    for (int i=0; i<n; i++) 
        m[arr[i]]++; 
  
    int twice_count = 0; 
  
    // iterate through each element and increment the 
    // count (Notice that every pair is counted twice) 
    for (int i=0; i<n; i++) 
    { 
        twice_count += m[sum-arr[i]]; 
  
        // if (arr[i], arr[i]) pair satisfies the condition, 
        // then we need to ensure that the count is 
        // decreased by one such that the (arr[i], arr[i]) 
        // pair is not considered 
        if (sum-arr[i] == arr[i]) 
            twice_count--; 
    } 
  
    // return the half of twice_count 
    return twice_count/2; 
} 


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