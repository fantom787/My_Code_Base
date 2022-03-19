#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

int main()
{
    int n;
    cin >> n;
    vector<int> in(n);
    bool zero = false;
    int sum = 0;
    int zf = 0;
    int tot = n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        in[i] = x;
        if (!x)
        {
            zf++;
            zero = true;
        }
    }
    if (!zero)
    {
        cout << -1 << endl;
        return 0;
    }
    sort(in.begin(), in.end());
    if (sum % 3 == 1)
    {
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (in[i] % 3 == 1)
            {
                idx = i;
                in[i] = -1;
                tot--;
                break;
            }
        }
        if (idx == -1)
        {
            int cnt = 0;
            for (int i = 0; i < n && cnt < 2; i++)
            {
                if (in[i] % 3 == 2)
                {
                    in[i] = -1;
                    tot--;
                    cnt++;
                }
            }
        }
    }

    else if (sum % 3 == 2)
    {
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (in[i] % 3 == 2)
            {
                idx = i;
                in[i] = -1;
                tot--;
                break;
            }
        }
        if (idx == -1)
        {
            int cnt = 0;
            for (int i = 0; i < n && cnt < 2; i++)
            {
                if (in[i] % 3 == 1)
                {
                    in[i] = -1;
                    cnt++;
                    tot--;
                }
            }
        }
    }
    if (zf == tot)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (in[i] == -1)
        {
            continue;
        }
        cout << in[i];
    }
    cout << endl;
    return 0;
}