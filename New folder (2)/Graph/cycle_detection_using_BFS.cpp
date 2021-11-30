#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

bool checkForCycle(int vertex, vi adj[], vi &vis, int v)
{
    queue<pair<int, int>> q;
    vis[vertex] = 1;
    q.push({vertex, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push({it, node});
            }
            else if (par != node)
            {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int v, vi adj[])
{
    vi vis(v + 1, 0);
    for (int i = 1; i < v + 1; i++)
    {
        if (checkForCycle(i, adj, vis, v))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi graph[8];
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(7);
    graph[3].push_back(2);
    graph[3].push_back(5);
    graph[4].push_back(6);
    graph[5].push_back(3);
    graph[5].push_back(7);
    graph[6].push_back(4);
    graph[7].push_back(2);
    graph[7].push_back(5);
    cout<<isCycle(7,graph);
    return 0;
}