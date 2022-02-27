#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // is n=2 then it is possible to sort regardless of the order of elements
    if (n == 2)
    {
        if (arr[0] <= arr[1])
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
        return 0;
    }
    /*
    intution: the only array that can be sorted is that
    1. they are already sorted
    2. already sorted but rotated

    approach:
    1. find the pivot


    */
    bool flag = true, ans = true;
    int pos = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (flag)
        {
            // finding the pivot
            if (arr[i + 1] < arr[i])
            {
                flag = false;
                pos = i;
            }
        }
        else
        {
            // now after finding pivot 1 aur baar pivot ata hai to mtlb array cant be sorted
            if (arr[i] > arr[i + 1])
            {
                ans = false;
            }
        }
    }
    // 1 more edge case is that pivot not found that means that means all are either incresing or equal if equal then its not roatated then its pivot is last element
    if (flag)
    {
        if (arr[0] == arr[n - 1])
        {
            flag = false;
            pos = n - 1;
        }
    }
    // 1 aur edge case agr dono sorted array hai bt last element is bda than 1st then also its impossible
    if (arr[0] < arr[n - 1])
    {
        ans = false;
    }
    if (!flag && ans)
    {
        cout << n - pos - 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}