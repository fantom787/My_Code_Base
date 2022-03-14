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
    int n;
    cin >> n;
    string ans = "";
    
    for (int i = 0; i < n; i++)
    {
        ans += ('a' + (i % 4));
    }
    cout << ans << endl;

    return 0;
}