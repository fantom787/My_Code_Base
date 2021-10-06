#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n, d;
    cin >> n >> d;
    if (n == 0)
    {
        cout << 1 << endl;
        return;
    }
    ll n1 = n;
    ll ans = 0;
    stack<ll> stk1;
    int i = 0;
    while (n1 > 0)
    {
        if (n1 % 10 == d)
        {
            stk1.push(i);
        }
        if (d == 9 && (n1 / 10) % 10 > 7)
        {
            stk1.push(i + 1);
        }

        i++;
        n1 /= 10;
    }

    while (!stk1.empty())
    {
        int temp = pow(10, stk1.top());
        if (d == 0)
        {
            while (!stk1.empty())
            {
                temp = pow(10, stk1.top());
                if (stk1.top() == 0)
                {
                    ans += 1;
                    break;
                }
                ans += temp  ;
                n += ans;
                stk1.pop();
            }
            break;
        }
        else if (d == 9)
        {
            temp = pow(10, stk1.top() + 1);
            ans += temp - n % temp;
            break;
        }
        else
        {
            ans += temp - n % temp;
            break;
        }
        stk1.pop();
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }

    return 0;
}