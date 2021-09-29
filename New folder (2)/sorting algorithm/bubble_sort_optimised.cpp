/*
simple sa funda hai ith elemet ko i+1 th element se compare kro 
and chota mil jaye to swap kr do
is tarah se tumhara array ke last me bde element ikkathe hote chale jayenge
aur tum sort kr loge
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

void bubblesort(int *arr, int size)
{
    int n = size - 1;
    for (int i = 0; i < n; i++)
    {
        int m = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                m++;
            }
        }
        if (m == 0)
        {
            cout << "the array is sorted  " << i << endl;
            break;
        }
    }
}

int main()
{
    int arr[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    bubblesort(arr, size);
    display(arr, size);

    return 0;
}