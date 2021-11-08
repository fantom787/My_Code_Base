#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void display(vvi arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 1)
            {
                cout << "K"
                     << " ";
            }
            else
            {
                cout << "."
                     << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int isvalid(vvi board, int row, int col)
{
    if (row >= 0 && row < board.size() && col >= 0 && col < board.size())
    {
        return 1;
    }
    return 0;
}

int isSafe(vvi board, int row, int col)
{
    //  checking for the
    if (isvalid(board, row - 2, col - 1) == 1)
    {
        if (board[row - 2][col - 1] == 1)
        {
            return 0;
        }
    }
    if (isvalid(board, row - 1, col - 2) == 1)
    {
        if (board[row - 1][col - 2] == 1)
        {
            return 0;
        }
    }
    if (isvalid(board, row - 2, col + 1) == 1)
    {
        if (board[row - 2][col + 1] == 1)
        {
            return 0;
        }
    }
    if (isvalid(board, row - 1, col + 2) == 1)
    {
        if (board[row - 1][col + 2] == 1)
        {
            return 0;
        }
    }
    return 1;
}
/*
        for nKnights
        agr hamara ghode sare place ho jate hai to wha pe apne board ko print kr do aur backtrack kr lo
        agr hamara pointer out of bound ho jata hai to use whi pe khtm kr do
        agr hamara ghoda safe hai kisi block pe to us block ko 1 kro aur ghode ko ghata ke  age ke liye bad jao
        fir backtrack kr jao
        agr safe nhi hai to bhi age bad jao bt ghode ko increase mt krna
*/
void nKnights(vvi &board, int row, int col, int knight)
{
    if (knight == 0)
    {
        display(board);
        return;
    }
    if (row == board.size() - 1 && col == board.size())
    {
        return;
    }

    if (col == board.size())
    {
        nKnights(board, row + 1, 0, knight);
        return;
    }
    if (isSafe(board, row, col))
    {
        board[row][col] = 1;
        nKnights(board, row, col + 1, knight - 1);
        board[row][col] = 0;
    }
    nKnights(board, row, col + 1, knight);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vvi board = {{0, 0}, {0, 0}};
    nKnights(board, 0, 0, 2);
    return 0;
}