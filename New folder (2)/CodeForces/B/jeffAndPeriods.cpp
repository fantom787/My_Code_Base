#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

int findD(vector<int> vec)
{
    int diff = vec[1] - vec[0];
    int currDiff = 0;
    int n = vec.size();
    for (int i = 1; i < n - 1; i++)
    {
        currDiff = vec[i + 1] - vec[i];
        if (currDiff != diff)
        {
            return 0;
        }
    }
    return diff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    map<int, int> ans;
    for (auto it : mp)
    {
        int n = it.second.size();
        if (n == 1)
        {
            ans[it.first] = 0;
        }
        else if (n == 2)
        {
            ans[it.first] = findD(it.second);
        }
        else
        {
            int cmnDiff = findD(it.second);
            if (cmnDiff)
            {
                ans[it.first] = cmnDiff;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}