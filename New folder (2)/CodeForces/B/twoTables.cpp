#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
// #define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n1, m1;
    cin >> n1 >> m1;
    vector<vector<int>> mat1(n1, vector<int>(m1));
    for (int i = 0; i < n1; i++)
    {
        string s1;
        cin >> s1;
        for (int j = 0; j < m1; j++)
        {
            mat1[i][j] = s1[j] - '0';
        }
    }
    int n2, m2;
    cin >> n2 >> m2;
    vector<vector<int>> mat2(n2, vector<int>(m2));
    for (int i = 0; i < n2; i++)
    {
        string s1;
        cin >> s1;
        for (int j = 0; j < m2; j++)
        {
            mat2[i][j] = s1[j] - '0';
        }
    }
    int ans = -1;
    int ansx = 0;
    int ansy = 0;
    for (int x = -50; x < 51; x++)
    {
        for (int y = -50; y < 51; y++)
        {
            int temp = 0;
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < m1; j++)
                {
                    if (x + i >= 0 && x + i < n2 && y + j >= 0 && y + j < m2)
                    {
                        temp += (mat1[i][j] * (mat2[i + x][j + y]));
                    }
                }
            }
            if (temp > ans)
            {
                ans = temp;
                ansx = x;
                ansy = y;
            }
        }
    }
    cout << ansx << " " << ansy << endl;
    return 0;
}