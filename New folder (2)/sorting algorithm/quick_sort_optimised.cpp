/*
bahut hi simple hai 
quick sort ko recrcively chalana hai partion ke left and right me
ab partion dekh lete hai
partion me kya krna hai ki
1 i lena hai and 1 j lena hai 
i ko low +1 ke barabar kr do
aur j ko high ke barabar kr do
i ko tab tk increment kro jb tk usse bda element na mil jaye
j ko tb tk decrement kro jb tk usse chota element na mil jaye 
nd i < j hai toh dono ko swap kr do
aur ye loop jb tk chalao jb tk i<j hai
last me a[low] ko swap kr do a[j] se 
and last me return kr do j ko
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

int partition(int *arr, int min, int max)
{
	int index = arr[min];
	int i = min + 1;
	int j = max;
	do
	{
		while (arr[i] <= index)
		{
			i++;
		}
		while (arr[j] > index)
		{
			j--;
		}
		if (i < j)
		{
			swap(arr[i], arr[j]);
		}

	} while (j > i);
	swap(arr[min], arr[j]);
	return j;
}

void quicksort(int *arr, int min, int max)
{
	int partition_index;
	if (min < max)
	{
		partition_index = partition(arr, min, max);
		quicksort(arr, min, partition_index - 1);
		quicksort(arr, partition_index + 1, max);
	}
}
// 	  0	 1  2 |3   4   5   6   7   8   9
//    7, 8, 2,|9, 45, 79, 25, 17, 54, 48

int main()
{

	int arr[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48, 1};
	int size = sizeof(arr) / sizeof(int);
	display(arr, size);
	quicksort(arr, 0, size - 1);
	display(arr, size);

	return 0;
}