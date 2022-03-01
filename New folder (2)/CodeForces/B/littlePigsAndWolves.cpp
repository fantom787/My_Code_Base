#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

void display(vector<vector<char>> grid)
{
    for (auto it : grid)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    vector<vector<char>> gridCopy = grid;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'P')
            {
                if (j - 1 >= 0 && gridCopy[i][j - 1] == 'W')
                {
                    gridCopy[i][j - 1] = '.';
                    ans++;
                }
                else if (j + 1 <= m - 1 && gridCopy[i][j + 1] == 'W')
                {
                    gridCopy[i][j + 1] = '.';
                    ans++;
                }
                else if (i - 1 >= 0 && gridCopy[i - 1][j] == 'W')
                {
                    gridCopy[i - 1][j] = '.';
                    ans++;
                }
                else if (i + 1 <= n - 1 && gridCopy[i + 1][j] == 'W')
                {
                    ans++;
                    gridCopy[i + 1][j] = '.';
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*

    0 1 2
    p w


*/