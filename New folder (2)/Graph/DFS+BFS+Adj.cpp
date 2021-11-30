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

vi bfs(int nodes, vi adj[])
{
    vi bfs;                   // we will store the bfs traversal value in this vector
    vi visited(nodes + 1, 0); //for marking the node is visited or not
    for (int i = 1; i < nodes + 1; i++)
    {
        if (visited[i] == 0)
        {
            // we create a queue and then push the not visited in the queue and mark it as visited
            queue<int> q;
            q.push(i);         //pushing it in the queue
            visited[i] = 1;    //marking it as visited
            while (!q.empty()) //now traversing till the queue does not become empty
            {
                int node = q.front(); // poping out the queue
                q.pop();
                bfs.push_back(node);      //pushing into our bfs vector
                for (auto it : adj[node]) //now checking its all adjecent / connected elements
                {
                    //if not visited then push it in to the queue
                    if (visited[it] == 0)
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    // at last return the vector
    return bfs;
}

void getDfs(vi adj[], vi &vis, vi &dfsVec, int node)
{
    dfsVec.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            getDfs(adj, vis, dfsVec, it);
        }
    }
}

vi dfs(int vertex, vi adj[])
{
    vi dfsVec;
    vi vis(vertex + 1, 0);
    for (int i = 1; i <= vertex; i++)
    {
        if (!vis[i])
        {
            getDfs(adj, vis, dfsVec, i);
        }
    }
    return dfsVec;
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
    cout << "BFS" << endl;
    display(bfs(7, graph));
    cout << "DFS" << endl;
    display(dfs(7, graph));
    return 0;
}