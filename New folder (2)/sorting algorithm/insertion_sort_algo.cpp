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
	int n = 0;
	int m = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				n++;
			}
			cout << " "<<m++;
			if (n == 0)
			{
				break;
			}
		}
	}
	cout << endl;
}

int main()
{

	int arr[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48};
	int size = sizeof(arr) / sizeof(int);
	display(arr, size);
	insertionsorting(arr,size);
	display(arr, size);
	insertionsorting(arr,size);
	display(arr, size);

	return 0;
}