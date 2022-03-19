#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    vector<int> q(m + 1);
    for (auto &it : p)
    {
        cin >> it;
    }
    for (auto &it : q)
    {
        cin >> it;
    }
    bool neg = false;
    if (n > m)
    {
        if (p[0] < 0 || q[0] < 0)
        {
            neg = true;
        }
        if (p[0] < 0 and q[0] < 0)
        {
            neg = false;
        }
        if (neg)
        {
            cout << "-Infinity" << endl;
        }
        else
        {
            cout << "Infinity" << endl;
        }
    }
    else if (n == m)
    {
        if (p[0] < 0 || q[0] < 0)
        {
            neg = true;
        }
        if (p[0] < 0 and q[0] < 0)
        {
            neg = false;
        }
        int first = abs(p[0]);
        int scnd = abs(q[0]);
        int cmn = __gcd(first, scnd);
        first /= cmn;
        scnd /= cmn;
        if (neg)
        {
            cout << "-";
        }
        cout << first << "/" << scnd << endl;
    }
    else
    {
        cout << 0 << "/" << 1 << endl;
    }
    return 0;
}