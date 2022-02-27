#include <bits/stdc++.h>
using namespace std;

#define endl "\n";
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    int i = 0;
    int j = 0;
    int sum = 0;
    while (j < n)
    {
        sum += arr[j];
        while (i <= j && sum > t)
        {
            sum -= arr[i++];
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    cout << ans << endl;
    return 0;
}