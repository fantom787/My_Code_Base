#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
void dfs(long long vertex, bool visited[], vector<long long> *AdjList)
{

    visited[vertex] = 1;

    for (auto i : AdjList[vertex])
        if (!visited[i])
            dfs(i, visited, AdjList);
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n];
    for (int i = 0; i < m; i++)
    {
        long long x, y;
        cin >> x >> y;
        x--, y--; // 0 based indexing
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool vis[n];
    memset(vis, false, sizeof(vis));
    dfs(0, vis, adj);
    ll count = 0;
    while (!vis[n - 1])
    {
        bool vis2[n];
        memset(vis2, false, sizeof(vis2));
        for (int i = 0; i < n; i++)
            if (vis[i])
            {
                if (i + 1 < n)
                    dfs(i + 1, vis2, adj);
                if (i - 1 >= 0)
                    dfs(i - 1, vis2, adj);
            }
        for (int i = 0; i < n; i++)
            vis[i] |= vis2[i];
        count++;
    }
    cout << count << endl;
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