#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
bool areParanthesisBalanced(string expr) ;

void permute(char *a, int l, int r) ;

void swap(char *a,char *b) ;

void rev(string& s,int l,int r) ;

int bsearch (string& s,int l,int r,int key) ;

// Find next greater number with same set of digits

void findNext(char number[], int n) ;

void reverseStr(string& str) ;

// Returns true if str1 and str2 are meta strings : Meta strings are the strings which can be made equal by exactly one swap in any of the strings
bool areMetaStrings(string str1, string str2) 

// Count of strings that can be formed using a, b and c under given constraints

// Given a length n, count the number of strings of length n that can be made using 
// ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed.

int countStr(int n, int bCount, int cCount) ;