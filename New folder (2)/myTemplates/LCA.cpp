struct lca_lift
{
    const int log = 21;
    int n;
    vector<vector<int>> edges;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> parent;

    void init(vector<vector<int>> e)
    {
        n = sz(e);
        edges = e;
        up = vector<vector<int>>(n + 10, vector<int>(log));
        depth = vector<int>(n + 10);
        parent = vector<int>(n + 10);
    }

    void init(int sz)
    {
        n = sz;
        edges = vector<vector<int>>(n + 10);
        up = vector<vector<int>>(n + 10, vector<int>(log));
        depth = vector<int>(n + 10);
        parent = vector<int>(n + 10);
    }

    void edge(int a, int b)
    {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    void dfs(int node, int par, int d)
    {
        depth[node] = d;
        parent[node] = par;
        for (auto it : edges[node])
        {
            if (it != par)
            {
                dfs(it, node, d + 1);
            }
        }
    }
    void init_lift(int v = 0)
    {
        dfs(0, -1, 0);
        parent[0] = 0;
        for (int i = 0; i < n; i++)
        {
            up[i][0] = parent[i];
        }
        for (int j = 1; j < log; j++)
        {
            for (int i = 0; i < n; i++)
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    int get_lca(int a, int b)
    {
        if (depth[a] < depth[b])
        {
            swap(a, b);
        }
        int dist = depth[a] - depth[b];
        for (int j = log - 1; j >= 0; j--)
        {
            if (dist & (1ll << j))
            {
                a = up[a][j];
            }
        }
        if (a == b)
        {
            return a;
        }
        for (int j = log - 1; j >= 0; j--)
        {
            if (up[a][j] != up[b][j])
            {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }

    int get_dist(int a, int b)
    {
        int v = get_lca(a, b);
        return depth[a] + depth[b] - 2 * depth[v];
    }
};