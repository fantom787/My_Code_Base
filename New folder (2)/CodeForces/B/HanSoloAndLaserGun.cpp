#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, xi, yi;
    cin >> n >> xi >> yi;
    set<pair<int,int>> st;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int num = y-yi;
        int den = x-xi;
        int common = __gcd(num,den);
        num/=common;
        den/=common;
        st.insert({num,den});
    }
    cout << st.size() << endl;
    return 0;
}