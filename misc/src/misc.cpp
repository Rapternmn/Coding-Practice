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


int climbStairs(int n) 
{
        
        int total[n+1];
        
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        else if(n>2)
        {
            total[0] = 0;
            total[1] = 1;
            total[2] = 2;
        }
        
        for(int i = 3; i <= n; i++)
            total[i] = total[i-1] + total[i-2] ;
            
        return total[n];
        
}

int sumBitDifferences(int arr[], int n) 
{ 
    int ans = 0;  // Initialize result 
  
    // traverse over all bits 
    for (int i = 0; i < 32; i++) 
    { 
        // count number of elements with i'th bit set 
        int count = 0; 
        for (int j = 0; j < n; j++) 
            if ( (arr[j] & (1 << i)) ) 
                count++; 
  
        // Add "count * (n - count) * 2" to the answer 
        ans += (count * (n - count) * 2); 
    } 
  
    return ans; 
} 

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

// function to print triplets with 0 sum 
void findTriplets(int arr[], int n) 
{ 
    bool found = false; 
  
    // sort array elements 
    sort(arr, arr+n); 
  
    for (int i=0; i<n-1; i++) 
    { 
        // initialize left and right 
        int l = i + 1; 
        int r = n - 1; 
        int x = arr[i]; 
        while (l < r) 
        { 
            if (x + arr[l] + arr[r] == 0) 
            { 
                // print elements if it's sum is zero 
                printf("%d %d %d\n", x, arr[l], arr[r]); 
                l++; 
                r--; 
                found = true; 
            } 
  
            // If sum of three elements is less 
            // than zero then increment in left 
            else if (x + arr[l] + arr[r] < 0) 
                l++; 
  
            // if sum is greater than zero than 
            // decrement in right side 
            else
                r--; 
        } 
    } 
  
    if (found == false) 
        cout << " No Triplet Found" << endl; 
} 

// Celebrity Problem

// Person with 2 is celebrity 
bool MATRIX[N][N] = {{0, 0, 1, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 1, 0}}; 
  
bool knows(int a, int b) 
{ 
    return MATRIX[a][b]; 
} 
  
// Returns -1 if celebrity 
// is not present. If present, 
// returns id (value from 0 to n-1). 
int findCelebrity(int n) 
{ 
    // Handle trivial  
    // case of size = 2 
  
    stack<int> s; 
  
    int C; // Celebrity 
  
    // Push everybody to stack 
    for (int i = 0; i < n; i++) 
        s.push(i); 
  
    // Extract top 2 
    int A = s.top(); 
    s.pop(); 
    int B = s.top(); 
    s.pop(); 
  
    // Find a potential celevrity 
    while (s.size() > 1) 
    { 
        if (knows(A, B)) 
        { 
            A = s.top(); 
            s.pop(); 
        } 
        else
        { 
            B = s.top(); 
            s.pop(); 
        } 
    } 
  
    // Potential candidate? 
    C = s.top(); 
    s.pop(); 
  
    // Last candidate was not  
    // examined, it leads one  
    // excess comparison (optimize) 
    if (knows(C, B)) 
        C = B; 
  
    if (knows(C, A)) 
        C = A; 
  
    // Check if C is actually 
    // a celebrity or not 
    for (int i = 0; i < n; i++) 
    { 
        // If any person doesn't  
        // know 'a' or 'a' doesn't  
        // know any person, return -1 
        if ( (i != C) && 
                (knows(C, i) ||  
                 !knows(i, C)) ) 
            return -1; 
    } 
  
    return C; 
} 

// Returns id of celebrity 
int findCelebrity(int n) 
{ 
    // Initialize two pointers  
    // as two corners 
    int a = 0; 
    int b = n - 1; 
  
    // Keep moving while  
    // the two pointers 
    // don't become same.  
    while (a < b) 
    { 
        if (knows(a, b)) 
            a++; 
        else
            b--; 
    } 
  
    // Check if a is actually 
    // a celebrity or not 
    for (int i = 0; i < n; i++) 
    { 
        // If any person doesn't  
        // know 'a' or 'a' doesn't 
        // know any person, return -1 
        if ( (i != a) && 
                (knows(a, i) ||  
                !knows(i, a)) ) 
            return -1; 
    } 
  
    return a; 
} 