#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void display(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int binary_search_m(int *arr, int low, int high, int target)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] < target)
		{
			low = mid + 1;
		}
		else if (arr[mid] > target)
		{
			high = mid - 1;
		}
		else if (arr[mid] == target)
		{
			return mid;
		}
	}
	return -1;
}

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

int search_in_rotated_array(int *arr, int size, int target)
{
	int piv = piviot(arr, size);
	int left = -2;
	int right = -2;
	left = binary_search_m(arr, 0, piv, target);
	right = binary_search_m(arr, piv + 1, size - 1, target);
	return max(left, right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[] = {2,9,2,2,2};
	int size = sizeof(arr) / sizeof(int);
	display(arr, size);
	int ans = piviot(arr, size);
	cout << ans << endl;
	return 0;
}