//find the missing number

//https://leetcode.com/problems/missing-number/submissions/

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
int missingNumber(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {

        while (array[i] != i)
        {
            if (array[i] >= array.size())
            {
                break;
            }
            swap(array[i], array[array[i]]);
        }
    }
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] != i)
        {
            return i;
        }
    }
    return array.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr = {3, 0, 1};
    display(arr);
    cout << missingNumber(arr) << endl;
    display(arr);

    return 0;
}