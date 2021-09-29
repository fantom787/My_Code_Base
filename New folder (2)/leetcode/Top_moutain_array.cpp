// https://leetcode.com/problems/longest-mountain-in-array/
// leetcode medium mouantain array

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

int Top_mountain_Array(int *arr, int size)
{
	int low = 0;
	int high = size - 1;
	int mid;
	int i = 0;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] > arr[mid + 1])
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[] = {1, 4, 7, 3, 2, 5};
	int size = sizeof(arr) / sizeof(int);
	display(arr, size);
	cout << Top_mountain_Array(arr, size);

	return 0;
}