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
void merge(int *arr, int low, int mid, int high, int size)
{
    int arr1[size];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            arr1[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            arr1[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        arr1[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        arr1[k] = arr[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = arr1[i];
    }
    free(arr1);
}

void merge_sort(int *arr, int low, int high, int size)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid, size);
        merge_sort(arr, mid + 1, high, size);
        merge(arr, low, mid, high, size);
    }
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

    cout << "Displaying Before Sorting" << endl;
    display(arr, size);
    cout << "Performing Insertion Sort" << endl;
    insertionsorting(arr, size);
    cout << "Displaying After Sorting" << endl;
    display(arr, size);
    cout << endl
         << endl;

    int arr1[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48};
    cout << "Displaying Before Sorting" << endl;
    display(arr1, size);
    cout << "Performing Selection Sort" << endl;
    selectionsort(arr1, size);
    cout << "Displaying After Sorting" << endl;
    display(arr1, size);
    cout << endl
         << endl;

    int arr2[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48};
    cout << "Displaying Before Sorting" << endl;
    display(arr2, size);
    cout << "Performing Bubble Sort" << endl;
    bubblesort(arr2, size);
    cout << "Displaying After Sorting" << endl;
    display(arr2, size);
    cout << endl
         << endl;

    int arr3[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48};
    cout << "Displaying Before Sorting" << endl;
    display(arr3, size);
    cout << "Performing Quick Sort" << endl;
    quicksort(arr3, 0, size - 1);
    cout << "Displaying After Sorting" << endl;
    display(arr3, size);
    cout << endl
         << endl;

    int arr4[] = {7, 8, 2, 9, 45, 79, 25, 17, 54, 48};
    cout << "Displaying Before Sorting" << endl;
    display(arr4, size);
    cout << "Performing Merge Sort" << endl;
    merge_sort(arr4, 0, size - 1, size);
    cout << "Displaying After Sorting" << endl;
    display(arr4, size);
    cout << endl
         << endl;

    return 0;
}