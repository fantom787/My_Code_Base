#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

bool checkCycle(vi graph[], vi vis, vi dfsVis, int node)
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : graph[node])
    {
        if (!vis[it] && checkCycle(graph, vis, dfsVis, it))
        {
            return true;
        }
        else if (dfsVis[it])
        {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}

bool isCycle(vi graph[], int vertex)
{
    vi vis(vertex + 1);
    vi dfsVis(vertex + 1);
    for (int i = 1; i < vertex + 1; i++)
    {
        if (!vis[i] && checkCycle(graph, vis, dfsVis, i))
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
    vi graph[10];
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[3].push_back(6);
    graph[4].push_back(5);
    graph[6].push_back(5);
    graph[7].push_back(2);
    graph[7].push_back(8);
    graph[8].push_back(9);
    graph[7].push_back(7);
    cout << isCycle(graph, 10);
    return 0;
}