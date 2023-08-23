// it is a path consisting of nodes in which every edge is taken once
// rules for undirected graph
// for eulerian cycle graph sud have same outgoing and same incoming edges
// for eulerian path graph can have atmost 1 in[i]-out[i]==1 and out[i]-in[i]==1
// code

auto dfs = [&](int node, auto &&dfs) -> void
{
    for (auto &it : edges[node])
    {
        if (!it[1])
        {
            it[1] = 1;
            dfs(it[0], dfs);
        }
    }
    s += (char(node + 'a'));
};