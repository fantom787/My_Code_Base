#include <bits/stdc++.h>
using namespace std;
#define ll long long int

map<int, int> graph;
map<int, int> visited;
int dfs(int start, int depth, int end)
{
    if (visited[start])
        return -1;
    else if (start == end)
        return depth;
    visited[start] = 1;
    return dfs(graph[start], depth + 1, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s, t;
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        graph[i] = temp;
    }
    cout << dfs(s, 0, t) << endl;

    return 0;
}