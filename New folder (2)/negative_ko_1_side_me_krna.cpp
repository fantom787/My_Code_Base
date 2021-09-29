#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void display(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void sortarr(int *arr, int size)
{
	int j = 0;

	for (int i = 1; i < size; i++)
	{
		if (arr[i] < 0)
		{
			swap(arr[i], arr[j]);
			j++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[] = {-6, -5, 2, 7, -8, 3, 9, 5, -1, -2, 5};
	int size = sizeof(arr) / sizeof(int);
	display(arr, size);
	sortarr(arr, size);
	display(arr, size);

	return 0;
}