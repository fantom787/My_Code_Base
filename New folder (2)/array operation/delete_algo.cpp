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

/*

5,7,6,8,1
7->6
6->8
8->1


*/
void delete_arr(int *arr, int *n, int index)
{
	index -= 1;
	for (int i = index; i < *n -1; i++)
	{
		arr[i] = arr[i + 1];
	}
	*n -= 1;
	realloc(arr, (*n) * sizeof(int));
}

int main()
{
	int n = 5;
	int *arr = (int *)malloc(sizeof(int) * n);
	arr[0] = 5;
	arr[1] = 7;
	arr[2] = 6;
	arr[3] = 1;
	arr[4] = 8;
	printarray(arr, n);
	int index = 2;
	delete_arr(arr, &n, index);
	printarray(arr, n);
	index = 4;
	delete_arr(arr, &n, index);
	printarray(arr, n);

	return 0;
}