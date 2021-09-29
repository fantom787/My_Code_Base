//287. Find the Duplicate Number

//https://leetcode.com/problems/find-the-duplicate-number/

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

        while (array[i] != i + 1)
        {
            if (array[i] == array[array[i] - 1])
            {
                return array[i];
            }
            swap(array[i], array[array[i] - 1]);
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr = {1,3,4,2,2};
    display(arr);
    cout << missingNumber(arr) << endl;
    display(arr);

    return 0;
}