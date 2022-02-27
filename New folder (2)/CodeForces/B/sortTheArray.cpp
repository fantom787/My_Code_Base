#include <bits/stdc++.h>
using namespace std;

#define ll long long int

/*
    intution
    bruteforce
    make a copy of the given array and then usko sort kr do
    now iterate in the sorted array find the first and last element which is not in place then reverse kr do us jagah se
    uske baad sort nhi hota to no print krke side holo
    warna yes aur idx+1 print krke side holo

*/

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
    vector<int> arr2 = arr;
    sort(arr2.begin(), arr2.end());
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr2[i])
        {
            l = i;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != arr2[i])
        {
            r = i;
        }
    }
    if (r == -1 || l == -1)
    {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    reverse(arr.begin() + r, arr.begin() + l + 1);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr2[i])
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    cout << r + 1 << " " << l + 1 << endl;

    return 0;
}