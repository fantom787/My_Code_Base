#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, d;
    cin >> n >> d;
    string str = to_string(n);
    ll len = str.length();
    if (d == 0)
    {
        int ind2 = len;
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '0')
            {
                str[1] = '1';
                ind2 = i;
                break;
            }
        }
        for (int i = ind2 + 1; i < len; i++)
        {
            str[i] = '1';
        }
    }
    else if (d == 9)
    {
        if (str[0] == 9)
        {
            for (int i = 0; i < len; i++)
            {
                str[i] = '0';
            }
            str = "1" + str;
        }
        else
        {
            int ind = len;
            for (int i = 0; i < len; i++)
            {
                if (str[i] == '9')
                {
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (str[j] <= '7')
                        {
                            str[j]++;
                            ind = j;
                            goto cvv;
                        }
                    }
                    for (int k = 0; k < len; k++)
                    {
                        str[i] = '0';
                    }
                    str = "1" + str;
                    goto fvv;
                }
            }
        cvv:;
            for (int j = ind + 1; j < len; j++)
            {
                str[j] = '0';
            }
        fvv:;
        }
    }
    else
    {
        int i = 0;
        for (int i = 0; i < len; i++)
        {
            if ((str[i] - 48) == d)
            {
                str[i] = str[i] + 1;
                break;
            }
        }
        for (int j = i + 1; j < len; j++)
        {
            str[j] = '0';
        }
    }
    ll nn = stoll(str);
    cout << nn - n << endl;
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