#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

bool checkForCycle(int vertex, vi adj[], vi &vis, int v, int par)
{
    vis[vertex] = 1;
    for (auto it : adj[vertex])
    {
        if (!vis[it])
        {
            if (checkForCycle(it, adj, vis, v, vertex))
                return true;
        }
        else if (it != par)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int v, vi adj[])
{
    vi vis(v + 1, 0);
    for (int i = 1; i < v + 1; i++)
    {
        if (checkForCycle(i, adj, vis, v, -1))
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
    cout << isCycle(7, graph);
    return 0;
}