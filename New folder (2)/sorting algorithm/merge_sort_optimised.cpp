/*
bahut simple hai
dekho merging ka scene ye hai ki 2 array hai usme se i  aur j th position pe 
jo bhi element hai unko compare kr do and daal do usko 
nye array me and last me purane wale array me copy kr dena
merge sort had se jyada easy hai
scene ye hai ki 1 mid banao aur usse pehle aur uske baad 
fir se isko recursively chalao 
and last me merge kr do
*/
#include <iostream>
using namespace std;

void display(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;
}

void merge(int *arr, int low, int mid, int high, int size)
{
	int arr1[size];
	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			arr1[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			arr1[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		arr1[k] = arr[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		arr1[k] = arr[j];
		j++;
		k++;
	}
	for (int i = low; i <= high; i++)
	{
		arr[i] = arr1[i];
	}
	free(arr1);
}

void merge_sort(int *arr, int low, int high, int size)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge_sort(arr, low, mid, size);
		merge_sort(arr, mid + 1, high, size);
		merge(arr, low, mid, high, size);
	}
}
int main()
{
	int arr[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48};
	int size = sizeof(arr) / sizeof(int);
	display(arr, size);
	merge_sort(arr, 0, size - 1, size);
	display(arr, size);
	return 0;
}