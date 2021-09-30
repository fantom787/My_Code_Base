//41. First Missing Positive

//https://leetcode.com/problems/first-missing-positive/

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
int firstMissingPositive(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        while (arr[i] != i + 1)
        {
            if (arr[i] <= 0 || arr[i] > arr.size() || arr[i] == arr[arr[i] - 1])
            {
                break;
            }
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    int i;
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return i+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr = {1, 2, 0};
    display(arr);
    cout << firstMissingPositive(arr) << endl;
    display(arr);

    return 0;
}