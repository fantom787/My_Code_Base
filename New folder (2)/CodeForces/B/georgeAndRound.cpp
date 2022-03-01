#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &it : a)
    {
        cin >> it;
    }
    for (auto &it : b)
    {
        cin >> it;
    }
    sort(a);
    sort(b);
    int ans = n;
    int pos = m-1;
    for(int i=n-1;i>=0;i--)
    {
        if(pos>=0&&a[i]<=b[pos])
        {
            ans--;
            pos--;
        }
    }
    cout << ans << endl;
    return 0;
}