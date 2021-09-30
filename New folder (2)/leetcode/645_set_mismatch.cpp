//645. Set Mismatch

//https://leetcode.com/problems/set-mismatch/

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

vector<int> findErrorNums(vector<int>& arr)
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
            ans.push_back(i+1);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr = {1,2,2,4};
    display(arr);
    display(findDuplicates(arr));
    display(arr);

    return 0;
}