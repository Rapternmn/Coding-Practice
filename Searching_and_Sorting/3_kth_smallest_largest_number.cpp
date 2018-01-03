#include<iostream>
#include<climits>
using namespace std;
 
int partition(int arr[], int l, int r);

int kthSmallest(int arr[], int l, int r, int k)
{
	if(k>0 && k<=r-l+1)
	{
		int pos = partition(arr,l,r)

		if(pos-l == k-1 )
			return arr[pos];
		if(pos-l > k-1 )
			return kthSmallest(arr,l,pos-1,k);
		return kthSmallest(arr,pos+1,r,k);
	}

	return INT_MAX;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
	int i = l;
	int pivot = arr[r];

	for(int j = l;j<r;j++)
	{
		if(arr[j]<=pivot)
		{
			swap(&arr[j],&arr[i]);
			i++;
		}
	}

	swap(&arr[i],&arr[r]);
	return i;
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k);
    return 0;
}