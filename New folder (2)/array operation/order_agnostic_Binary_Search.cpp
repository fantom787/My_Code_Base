#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool decide(int *arr, int size)
{
	return arr[0] < arr[size - 1] ? true : false;
}

int binary_search(int *arr, int size, int target)
{
	bool ace_des = decide(arr, size);
	int low = 0;
	int mid, high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == target)
			return mid + 1;
		if (ace_des)
		{
			if (arr[mid] > target)
			{
				high = mid - 1;
			}
			else if (arr[mid] < target)
			{
				low = mid + 1;
			}
		}
		else
		{
			if (arr[mid] < target)
			{
				high = mid - 1;
			}
			else if (arr[mid] > target)
			{
				low = mid + 1;
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[] = {2, 4, 6, 8, 10};
	int arr1[] = {10,8,6,4,2};
	int size = sizeof(arr) / sizeof(int);
	int size1 = sizeof(arr1) / sizeof(int);
	cout << binary_search(arr, size, 10)<<endl;
	cout << binary_search(arr1, size1, 10);

	return 0;
}