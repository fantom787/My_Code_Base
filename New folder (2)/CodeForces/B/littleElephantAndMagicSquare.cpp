#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>> mat(3, vector<int>(3));
    vector<int> eqn(3);
    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> mat[i][j];
            temp += mat[i][j];
        }
        eqn[i] = temp;
    }
    int y = (eqn[2] - (eqn[1] - eqn[0])) / 2;
    int x = eqn[1] + y - eqn[0];
    int z = eqn[1] + y - eqn[2];
    mat[0][0] = x;
    mat[1][1] = y;
    mat[2][2] = z;
    for (auto it : mat)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}