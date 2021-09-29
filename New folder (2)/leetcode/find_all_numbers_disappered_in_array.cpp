//448. Find All Numbers Disappeared in an Array

//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

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
vector<int> findDisappearedNumbers(vector<int> &array)
{
    vector<int> ans;
    for (int i = 0; i < array.size(); i++)
    {
        while (array[i] != i + 1)
        {
            if (array[i] == array[array[i] - 1])
            {
                break;
            }
            swap(array[i], array[array[i] - 1]);
        }
    }
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] != i + 1)
        {
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
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    display(arr);
    display(findDisappearedNumbers(arr));
    display(arr);

    return 0;
}