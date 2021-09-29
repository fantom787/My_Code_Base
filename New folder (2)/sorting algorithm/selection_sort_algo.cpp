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

void selectionsort(int *arr, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = size -1 ; j > i ; j--)
		{
			if (arr[j-1]>arr[j])
			{
				swap(arr[j-1],arr[j]);
			}
			
		}
		
	}
	
}
// 	  0	 1  2 |3   4   5   6   7   8   9
//    7, 8, 2,|9, 45, 79, 25, 17, 54, 48

int main()
{

	int arr[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48, 1};
	int size = sizeof(arr) / sizeof(int);
	display(arr, size);
	selectionsort(arr, size);
	display(arr, size);

	return 0;
}