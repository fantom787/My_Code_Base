#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    unordered_set<int> st;
    if (n == k)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> arr(n);
    int i = n;
    int iter = n - 1;
    while (k--)
    {
        arr[iter--] = i--;
    }
    arr[iter--] = 1;
    while (iter >= 0)
    {
        arr[iter--] = i--;
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}