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

void findTopoSort(vi graph[], vi &vis, stack<int> &st, int node)
{
    vis[node] = 1;
    st.push(node);
    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            findTopoSort(graph, vis, st, it);
        }
    }
}

vi topoSort(vi graph[], int vertex)
{
    vi tpsort;
    stack<int> s;
    vi vis(vertex);
    for (int i = 0; i < vertex + 1; i++)
    {
        // cout<<"hi i m in the topo sort ke for loop"<<endl;
        if (!vis[i])
        {
            findTopoSort(graph, vis, s, i);
        }
    }
    while (!s.empty())
    {
        tpsort.push_back(s.top());
        s.pop();
    }
    return tpsort;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vi graph[6];
    graph[2].push_back(3);
    graph[3].push_back(1);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[5].push_back(0);
    graph[5].push_back(2);
    display(topoSort(graph, 6));

    return 0;
}