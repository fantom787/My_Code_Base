/*

    the idea is we store the exit time of all the nodes 
    and then according to the exit time of each node we sort the edges
    we make 2 graph
    1 simple
    another with reverse edges
    so if there is a node from scc1--> scc2 
    then in the reverse graph there will be a node from scc2-->scc1
    so since we have sorte all the nodes according to the max ending time 
    so scc1 nodes will be on the top and now
    we can do dfs on reverse graph and store all the nodes of scc1 in a vector

    scc ---> it store the nodes of a scc
    the order is scc1---> scc2---> scc3--->scc3.......

*/

struct SCC
{
    int n, timer = 0;
    vector<vector<int>> edges;
    vector<vector<int>> redges;
    vector<vector<int>> scc;
    vector<int> time, vis, nodes;
    void edge(int u, int v)
    {
        edges[u].pb(v);
        redges[v].pb(u);
    }
    void init(int rn)
    {
        n = rn;
        edges = vector<vector<int>>(n);
        redges = vector<vector<int>>(n);
        time = vector<int>(n);
        vis = vector<int>(n);
        nodes = vector<int>(n);
        iota(all(nodes), 0ll);
    }
    void dfs(int node)
    {
        vis[node] = 1;
        for (auto it : edges[node])
        {
            if (!vis[it])
            {
                dfs(it);
            }
        }
        time[node] = timer++;
    }
    void dfs1(int node, vector<int> &temp)
    {
        vis[node] = 1;
        temp.pb(node);
        for (auto it : redges[node])
        {
            if (!vis[it])
            {
                dfs1(it, temp);
            }
        }
    }
    void run()
    {
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }
        sort(all(nodes), [&](int i, int j)
             { return time[i] > time[j]; });
        vis = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[nodes[i]])
            {
                vector<int> temp;
                dfs1(nodes[i], temp);
                scc.pb(temp);
            }
        }
    }
};