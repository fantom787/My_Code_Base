#include <iostream>
using namespace std;
int darraysize = 0;
void show(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// if any duplicate element found will return 1 else 0
int duplicatefinder(int *arr, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    return 0;
}
// for sorting
void sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
int *duplicate(int *arr, int size)
{
    // copying the array
    int temparr[size];
    for (int i = 0; i < size; i++)
    {
        temparr[i] = arr[i];
    }
    sort(temparr, size);
    int *ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (temparr[i] == temparr[i + 1] && duplicatefinder(ptr, darraysize, temparr[i]) == 0)
        {
            ptr[darraysize] = temparr[i];
            darraysize++;
        }
    }

    return ptr;
}
int *nduplicate(int *arr, int size, int *ptr)
{
    int *ptr1 = new int[darraysize];
    for (int i = 0; i < darraysize; i++)
    {
        ptr1[i] = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == ptr[i])
            {
                ptr1[i] += 1;
            }
        }
    }
    return ptr1;
}

int main()

{

    int arr[] = {1, 1, 1, 1, 2, 2, 2, 41, 41, 84, 84, 9, 9, 9};
    // 1 1 1 1 2 2 2 9 9 9 41 84 84
    int size = sizeof(arr) / sizeof(int);
    int *ptr = duplicate(arr, size);
    show(ptr, darraysize);
    int*ptr1 = nduplicate(arr,size,ptr);
    show(ptr1,darraysize);

    return 0;
}