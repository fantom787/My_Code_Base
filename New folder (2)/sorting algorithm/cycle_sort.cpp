#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// only use when it is given that the array is from i to n
void cycle_sort(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        while (array[i] != i + 1)
        {
            swap(array[i], array[array[i] - 1]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr = {3, 5, 2, 1, 4};
    display(arr);
    cycle_sort(arr);
    display(arr);

    return 0;
}