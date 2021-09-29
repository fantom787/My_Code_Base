#include <iostream>
using namespace std;
void printarray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void insert(int *arr, int *n, int value, int index)
{
	realloc(arr, (*n + 1) * sizeof(int));
	for (int i = (*n); i > index - 1; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[index - 1] = value;
	*n += 1;
}

int main()
{
	int n = 6;
	int *arr = (int *)malloc(sizeof(int) * (n));
	arr[0] = 5;
	arr[1] = 6;
	arr[2] = 2;
	arr[3] = 8;
	arr[4] = 2;
	arr[5] = 9;
	int value = 56, index = 4;
	printarray(arr, n);
	insert(arr, &n, value, index);
	printarray(arr, n);
	value = 69, index = 7;
	insert(arr, &n, value, index);
	printarray(arr, n);
	
	return 0;
}