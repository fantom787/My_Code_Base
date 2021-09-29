/*
	bahut simple hai 
	dekho array lena hai isme sbse bda element dhundhna hai aur fir usi ke size
	ka array bna dena hai 
	fir uske har element ko 0 kr do 
	and fir apne original array ko iterate kro 
	aur jo element milta hai wo nye array ke us position ki value set kr do
	aur fir 1 loop chalao jisme jo 1 nhi hai usko apne purane array me daal do
	simple !!!
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

int max(int *arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

void countsort(int *arr, int size)
{
	int size1 = max(arr, size) + 1;
	int *b = new int[size1];
	int n = 0;
	for (int i = 0; i < size1; i++)
	{
		b[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		b[arr[i]] += 1;
	}
	for (int i = 0; i < size1; i++)
	{
		while (b[i] != 0)
		{
			arr[n] = i;
			b[i] -= 1;
			n++;
		}
	}
	free(b);
}

int main()
{
	int arr[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48,2};
	int size = sizeof(arr) / sizeof(int);
	display(arr, size);
	countsort(arr,size);
	display(arr, size);

	return 0;
}