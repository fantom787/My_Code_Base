#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort012(int *arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high]);
            high -= 1;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[] = {1, 0, 0, 2, 0, 1, 0, 2, 0, 1};
    int size = sizeof(arr) / sizeof(int);
    printarray(arr, size);
    sort012(arr, size);
    printarray(arr, size);

    return 0;
}