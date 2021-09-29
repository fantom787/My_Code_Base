/*
simple sa funda hai ith elemet ko min let kro then usko pure baki array se compare kro and then usse chota koi mile
toh usse replace kr do 
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

void selectionsort(int *arr, int size)
{
	int minindex;
	for (int i = 0; i < size - 1; i++)
	{
		minindex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minindex])
			{
				minindex = j;
			}
		}
		swap(arr[i], arr[minindex]);
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