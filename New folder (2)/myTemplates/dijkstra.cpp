struct dijkstra
{
    int n;
    const ll inf = 4e18;
    vector<ll> dists; /* for a single run */
    vector<int> par;
    vector<bool> vis;
    vector<vector<pair<int, int>>> edges;

    void init(int s)
    {
        n = s;
        dists = vector<ll>(n + 10);
        vis = vector<bool>(n + 10);
        par = vector<int>(n + 10);
        edges = vector<vector<pair<ll, int>>>(n + 10);
    }

    void edge(int a, int b, int wt)
    {
        edges[a].push_back(make_pair(wt, b));
        edges[b].push_back(make_pair(wt, a));
    }

    using ptype = pair<int, int>;
    void run(int src)
    {
        fill(dists.begin(), dists.end(), INF);
        fill(vis.begin(), vis.end(), 0);
        fill(par.begin(), par.end(), -1);

        min_heap<ptype> pq;
        dists[src] = 0;
        pq.push(make_pair(0, src));
        while (!pq.empty())
        {
            ptype foc = pq.top();
            pq.pop();

            if (vis[foc.S])
                continue;
            vis[foc.S] = 1;

            dists[foc.S] = min(dists[foc.S], foc.F);
            for (ptype x : edges[foc.S])
            {
                ll d = dists[foc.S] + x.F;
                if (d < dists[x.S])
                {
                    dists[x.S] = d;
                    par[x.S] = foc.S;
                    pq.push(make_pair(d, x.S));
                }
            }
        }
    }
};