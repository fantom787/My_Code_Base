#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define pb push_back

void display(vector<int> vec)
{
    cout << "displaying vector" << endl;
    for (auto it : vec)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> mp(k + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    bool f1 = true;
    int ans = -1;
    while (f1)
    {
        ans++;
        f1 = false;
        for (int i = k - 1; i > 0; i--)
        {
            if (mp[i] > 0)
            {
                mp[i]--;
                mp[i + 1] += 1;
                f1 = true;
            }
        }
        // display(mp);
    }
    cout << ans << endl;
    return 0;
}

/*
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> sol(n);
    for (auto &it : sol)
    {
        cin >> it;
    }
    int ans = 0;
    int m = 10;
    while (1)
    {
        map<int, int> mp;
        for (auto it : sol)
        {
            mp[it]++;
        }
        auto fnd = mp.find(k);
        if (fnd != mp.end() && fnd->second == n)
        {
            break;
        }
        else
        {
            vector<int> temp;
            for (auto it : mp)
            {
                int first = it.first;
                int scnd = it.second;
                if (first < k)
                {
                    temp.pb(first + 1);
                    for (int i = 0; i < scnd - 1; i++)
                    {
                        temp.pb(first);
                    }
                }
                else
                {
                    for (int i = 0; i < scnd; i++)
                    {
                        temp.pb(first);
                    }
                }
            }
            sol = temp;
        }
        sort(all(sol));
        // display(sol);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
*/