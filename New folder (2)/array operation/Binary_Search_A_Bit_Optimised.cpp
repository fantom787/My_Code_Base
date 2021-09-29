#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int binary_search(int *arr, int size, int target)
{
	int low = 0;
	int mid, high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] > target)
		{
			high = mid - 1;
		}
		else if (arr[mid] < target)
		{
			low = mid + 1;
		}
		else if (arr[mid] == target)
			return mid+1;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[] = {2,4,6,8,10};
	int size = sizeof(arr)/sizeof(int);
	cout<<binary_search(arr,size,10);

	return 0;
}