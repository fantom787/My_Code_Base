#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int piviot(int *arr, int size)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] > arr[mid + 1])
		{
			return mid;
		}
		else if (arr[mid] < arr[mid - 1])
		{
			return mid - 1;
		}
		else if (arr[low] == arr[mid] && arr[mid] == arr[high])
		{
			// what if low was the piviot
			if (arr[low] > arr[low + 1])
			{
				return low;
			}
			low++;
			// what if high is piviot
			if (arr[high] > arr[high - 1])
			{
				return high;
			}
			high--;
		}
		// left ki condition check kr lo
		else if (arr[mid] < arr[low])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[] = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2};
	int size = sizeof(arr) / sizeof(int);
	cout << "the number of times array rotated is = to piviot times " << piviot(arr, size) + 1 << endl;

		return 0;
}