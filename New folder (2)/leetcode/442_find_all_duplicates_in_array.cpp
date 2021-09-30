//442. Find All Duplicates in an Array

//https://leetcode.com/problems/find-all-duplicates-in-an-array/

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

vector<int> findDuplicates(vector<int> &arr)
{
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        while (arr[i] != i + 1)
        {
            if (arr[i] == arr[arr[i] - 1])
            {
                break;
            }
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != i + 1)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    display(arr);
    display(findDuplicates(arr));
    display(arr);

    return 0;
}