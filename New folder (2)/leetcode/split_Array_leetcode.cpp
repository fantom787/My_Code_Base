//https://leetcode.com/problems/split-array-largest-sum/
/*
	question ye hai ki hme 1 array ko m sub array me todna hoga 
	un sub array ka max sum leke 
	jitni possibility bni utno me se smallest sum lena hoga
*/
// bruteforce --> sare subarray lo aur unka largest fir smallest sum nikalo
// optimised aproach is through binary search lets code it

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int split_Array(int *arr, int size, int m)
{
	int start = 0;
	int end = 0;
	for (int i = 0; i < size; i++)
	{
		start = max(arr[i], start);
		end += arr[i];
	}
	// binary search
	while (start < end)
	{
		// try for the middle for the potential answer
		int mid = start + (end - start) / 2;
		int sum = 0;
		int pieces = 1;
		for (int i = 0; i < size; i++)
		{
			// check if the sum is less than my mid or not
			if (sum + arr[i] > mid)
			{
				sum = arr[i];
				pieces++;
			}
			else
			{
				sum += arr[i];
			}
		}
		// if we are deviding our array in more than m pieces this means indivdual sum of sub array is small and this means that we have taken too small value for the mid
		if (pieces > m)
		{
			start = mid + 1;
		}
		// if we are dividing in less pieces thenn this means that individual sum is large so we have taken a very large value
		else if (pieces <= mid)
		{
			end = mid;
		}
	}
	return start;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[] = {7, 2, 5, 10, 8};
	int size = sizeof(arr) / sizeof(int);
	cout << split_Array(arr, size, 2);

	return 0;
}