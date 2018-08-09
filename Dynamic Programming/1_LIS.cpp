/* Dynamic Programming C/C++ implementation of LIS problem */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int lis( int arr[], int n )
{
	vector<int> lis;

	for(int i = 0;i<n;i++)
		lis.push_back(1);

	for(int i = 1;i<n;i++)
		for(int j = 0;j<i;j++)
			if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	
	int max_elem = *max_element(lis.begin(),lis.end());

	return max_elem;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d \n", lis( arr, n ) );
    return 0;
}
