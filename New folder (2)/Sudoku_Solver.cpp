#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void display(vvi board)
{
    int n = board.size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}
/*
    for is safe ke liye
    check kro ki us coloumn and ur row me wo element to nhi hai
    agr hai to 0 return kr do
    and fir check kro ki us box me to nhi hai na
    uska formula hai row = row - row%n
    where n is the sqrt of the size of the sudoku
*/
int issafe(vvi &board, int row, int col, int element)
{
    //  for row
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == element)
        {
            return 0;
        }
    }
    //  for coloumn
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == element)
        {
            return 0;
        }
    }

    //  checking in the box itself
    int n = sqrt(board.size());
    int checkrow = row - row % n;
    int checkcol = col - col % n;
    for (int row1 = checkrow; row < checkrow + n; row++)
    {
        for (int col1 = checkcol; col < checkcol + n; col++)
        {
            if (board[row1][col1] == element)
            {
                return 0;
            }
        }
    }
    return 1;
}

int sudoku_solver(vvi &board)
{
    int n = board.size();
    int row = -1;
    int col = -1;
    int empty_left = 1;
    for (int row1 = 0; row1 < n; row1++)
    {
        for (int col1 = 0; col1 < n; col1++)
        {
            if (board[row1][col1] == 0)
            {
                row = row1;
                col = col1;
                empty_left = 0;
            }
        }
        if (empty_left == 0)
        {
            break;
        }
    }
    if (empty_left == 1)
    {
        // sudoku is solved as no empty item is found
        return 1;
    }
    for (int num = 1; num <= 9; num++)
    {
        if (issafe(board, row, col, num) == 1)
        {
            board[row][col] = num;
            if (sudoku_solver(board) == 1)
            {
                return 1;
            }
            else
            {
                // backtrack
                board[row][col] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vvi board = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    cout << "Before solving" << endl;
    display(board);
    cout << endl;
    sudoku_solver(board);
    cout << "After solving" << endl;
    display(board);
    return 0;
}