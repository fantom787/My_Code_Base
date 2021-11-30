// https://www.codechef.com/problems/BININV
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void solve()
{
    ll n;
    ll m;
    cin >> n >> m;
    vector<string> bi;
    vector<pair<ll, ll>> ones;
    for (int i = 0; i < n; i++)
    {
        ll onesTemp = 0;
        string temp;
        cin >> temp;
        bi.push_back(temp);
        for (int i = 0; i < m; i++)
        {
            if (temp[i] == '1')
            {
                onesTemp++;
            }
        }
        ones.push_back({onesTemp, i});
    }
    sort(all(ones));
    string ans;
    for (int i = 0; i < n; i++)
    {
        ll temp = ones[i].second;
        ans += bi[temp];
    }
    ll totalOnes = 0;
    ll finalAns = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == '1')
        {
            totalOnes++;
        }
        else
        {
            finalAns += totalOnes;
        }
    }
    cout << finalAns <<"\n";
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