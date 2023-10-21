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