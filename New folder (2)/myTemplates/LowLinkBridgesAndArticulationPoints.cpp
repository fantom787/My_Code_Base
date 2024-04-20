class lowlink
{
    int n;
    vector<vector<int>> graph;
    vector<vector<int>> dfs_tree;
    vector<int> root;
    vector<bool> used;
    vector<int> ord, low;
    vector<int> cnt;
    vector<pair<int, int>> bridge;
    void dfs(int u, int &k, int p)
    {
        ord[u] = low[u] = k++;
        used[u] = true;
        for (int v : graph[u])
        {
            if (!used[v])
            {
                dfs(v, k, u);
                dfs_tree[u].push_back(v);
                amin(low[u], low[v]);
                if (ord[u] < low[v])
                    bridge.push_back({u, v});
            }
            else if (v != p)
                amin(low[u], ord[v]);
        }
    }

public:
    lowlink(vector<vector<int>> g)
    {
        n = g.size();
        graph = g;
        dfs_tree = vector<vector<int>>(n);
        used = vector<bool>(n);
        ord = vector<int>(n);
        low = vector<int>(n);
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                root.push_back(i);
                dfs(i, k, -1);
            }
        }
    }
    int count_component()// returns the number of components
    {
        return root.size();
    }
    int count_component_diff(int u)// returns the change in the number of components when ith node is removed
    {
        if (binary_search(all(root), u))
        {
            int c = dfs_tree[u].size();
            return c - 1;
        }
        else
        {
            int c = 0;
            for (int v : dfs_tree[u])
            {
                if (ord[u] <= low[v])
                    c++;
            }
            return c;
        }
    }
};
/*
https://atcoder.jp/contests/abc334/submissions/48843893
*/