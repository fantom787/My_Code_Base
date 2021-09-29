/*
simple sa funda hai ith element ko key maan lo aur usee pehle ke elements 
se compare karao jab tak usse chota element nhi mil jata
and last me us chote element ke next wali positon pe wo key daal do
warna tb tk shift krte rho j ko j+1 pe
*/
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void display(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;
}

void insertionsorting(int *arr, int size)
{
	int key = 0;
	int j = 0;
	for (int i = 1; i <= size - 1; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
// 	  0	 1  2 |3   4   5   6   7   8   9
//    7, 8, 2,|9, 45, 79, 25, 17, 54, 48

int main()
{

	int arr[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48};
	int size = sizeof(arr) / sizeof(int);
	display(arr, size);
	insertionsorting(arr, size);
	display(arr, size);

	return 0;
}