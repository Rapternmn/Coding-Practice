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
