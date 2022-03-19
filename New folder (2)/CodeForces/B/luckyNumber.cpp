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
    string in;
    cin >> in;
    int n = in.size();
    if (n % 2)
    {
        n += 1;
    }
    else
    {
        string temp;
        for (int i = 0; i < n / 2; i++)
        {
            temp += '7';
        }
        for (int i = 0; i < n / 2; i++)
        {
            temp += '4';
        }
        if (temp < in)
        {
            n += 2;
        }
    }
    string ans;
    for (int i = 0; i < n / 2; i++)
    {
        ans += '4';
    }
    for (int i = 0; i < n / 2; i++)
    {
        ans += '7';
    }
    do
    {
        if (ans >= in || n > in.size())
        {
            break;
        }

    } while (next_permutation(ans.begin(), ans.end()));
    cout << ans << endl;
    return 0;
}
/*

9999
444777

99999
444777


*/