#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

bool bfs(vi adj[], vi &col, int node)
{
    queue<int> q;
    col[node] = 1;
    q.push(node);
    while (!q.empty())
    {
        int newNode = q.front();
        q.pop();
        for (auto it : adj[newNode])
        {
            if (col[it] == -1)
            {
                col[it] = 1 - col[newNode];
                q.push(it);
            }
            else if (col[it] == col[newNode])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vi adj[], int v)
{
    vi col(v + 1, -1);
    for (int i = 1; i < v + 1; i++)
    {
        if (col[i] == -1)
        {
            if (!bfs(adj, col, i))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vi graph[9];
    // graph[1].push_back(2);
    // graph[2].push_back(1);
    // graph[2].push_back(3);
    // graph[2].push_back(7);
    // graph[3].push_back(2);
    // graph[3].push_back(5);
    // graph[4].push_back(6);
    // graph[5].push_back(3);
    // graph[5].push_back(7);
    // graph[6].push_back(4);
    // graph[7].push_back(2);
    // graph[7].push_back(5);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(7);
    graph[3].push_back(2);
    graph[3].push_back(5);
    graph[4].push_back(6);
    graph[5].push_back(3);
    graph[5].push_back(8);
    graph[6].push_back(4);
    graph[7].push_back(2);
    graph[7].push_back(8);
    graph[8].push_back(5);
    graph[8].push_back(7);
    cout << isBipartite(graph, 8);
    return 0;
}