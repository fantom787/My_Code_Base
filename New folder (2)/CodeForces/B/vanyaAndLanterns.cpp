#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, l;
    cin >> n >> l;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    double diff = max(arr[0] - 0, l - arr[n - 1]);
    for (int i = 1; i < n; i++)
    {
        diff = max(diff, (double)(arr[i] - arr[i - 1]) / 2);
    }
    cout<<fixed<<setprecision(9)<<diff<<endl;
    return 0;
}