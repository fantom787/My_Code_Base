#include <iostream>
using namespace std;

int binarysearch(int *arr, int size, int element)
{
    int low = 0, high = size, mid;
    if (element == arr[low])
    {
        return low;
    }
    if (element == arr[high])
    {
        return high;
    }
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (element == arr[mid])
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444, 455};
    int size = sizeof(arr) / sizeof(int);
    int element = 455;
    int searchIndex = binarysearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);

    return 0;
}