#include <bits/stdc++.h>
using namespace std;

#define endl "\n";
#define ll long long int

void display(vector<vector<int>> mat)
{
    for (auto it : mat)
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
    unordered_map<int, int> row, col;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            col[j] = 0;
            cin >> mat[i][j];
        }
        row[i] = 0;
    }
    vector<vector<int>> a(m, vector<int>(n, 1));
    for (int i = 0; i < m; i++)
    {
        bool flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (!mat[i][j])
            {
                if (!flag)
                {
                    for (int k = 0; k < n; k++)
                    {
                        a[i][k] = 0;
                    }
                    flag = 1;
                }
                for (int k = 0; k < m; k++)
                {
                    a[k][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j])
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    vector<vector<int>> b(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] || col[j])
                b[i][j] = 1;
        }
    }
    if (b == mat)
    {
        cout << "YES" << endl;
        display(a);
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}