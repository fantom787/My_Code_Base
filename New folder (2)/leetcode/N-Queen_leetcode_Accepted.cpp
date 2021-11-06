#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

class Solution
{
public:
    vector<vector<string>> sol;
    bool isValid(vector<string> &chess, int row, int col, int n)
    {
        for (int i = row - 1, j = col; i >= 0; i--)
        {
            if (chess[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chess[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chess[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solve(vector<string> &board, int n, int row)
    {
        if (row == n)
        {
            sol.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(board, row, col, n))
            {
                board[row][col] = 'Q';
                solve(board, n, row + 1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        solve(board, n, 0);
        return sol;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}