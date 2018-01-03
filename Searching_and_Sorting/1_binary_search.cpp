#include <stdio.h>

int binary_search(int arr[], int l, int r, int x)
{
	if(l<=r)
	{
		mid = l + (r-l)/2 ;

		if(arr[mid] == x)
			return mid

		else if(arr[mid] > x)
			return binary_search(arr,l,mid-1,x);
		else
			return binary_search(arr,mid+1,r,x);
	}
	return -1;
}