#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void display(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int kaden(int *arr, int size)
{
	int sum = 0, max1 = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
		sum = max(sum, 0);
		max1 = max(sum, max1);
	}
	return max1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int size = sizeof(arr) / sizeof(int);
	display(arr, size);
	cout << kaden(arr, size) << endl;

	return 0;
}