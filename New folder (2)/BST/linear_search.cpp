#include <iostream>
using namespace std;

int linearsearch(int *arr, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12};
    int size = sizeof(arr) / sizeof(int);
    int element = 4;
    int adress = linearsearch(arr, size, element);
    if (adress != 0)
    {
        cout << "the element :" << element << " was found at " << adress<<" index of array" << endl;
    }
    else
    {
        cout << "the element : " << element << "was not found in the array" << endl;
    }

    return 0;
}