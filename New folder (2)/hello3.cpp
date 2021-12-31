#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void display(vi vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }
    cout << endl;
}

void dfs(vi graph[], int node, vi vis, stack<int> st)
{
    vis[node] = 1;
    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            dfs(graph, it, vis, st);
        }
    }
    st.push(node);
}

vi topoSort(vi graph[], int vertex)
{
    vi sort;
    vi vis(vertex + 1, 0);
    stack<int> st;
    for (int i = 0; i < vertex + 1; i++)
    {
        if (!vis[i])
        {
            dfs(graph, i, vis, st);
        }
    }
    while (!st.empty())
    {
        sort.push_back(st.top());
        st.pop();
    }
    return sort;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi graph[5];
    graph[2].push_back(3);
    graph[3].push_back(1);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[5].push_back(0);
    graph[5].push_back(2);
    display(topoSort(graph, 5));
    return 0;
}