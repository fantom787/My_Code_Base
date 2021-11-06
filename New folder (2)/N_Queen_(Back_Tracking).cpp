#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
/*
    ******* Algo Discussion ********
    dekho simple sa funda hai
    1st row me queen ko place kro uski next row ke har
    coloumn pe queen rkh skte hai ki nhi wo check kro
    aur possible hai to rkh ke nxt row me check krne ki reccursion call chalao
    fir us call ke baad us jagha se queen ko hta ke next jagah lga ke dekho 
    bs yhi hai simple sa logic
*/
void display(vvi arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 1)
            {
                cout << "Q"
                     << " ";
            }
            else
            {
                cout << "X"
                     << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int isSafe(vvi &chess, int r, int c)
{
    // for verticle
    for (int i = 0; i < r; i++)
    {
        if (chess[i][c] == 1)
        {
            return 0;
        }
    }
    //  for diagonal left
    int maxleft = min(r, c);
    for (int i = 1; i <= maxleft; i++)
    {
        if (chess[r - i][c - i] == 1)
        {
            return 0;
        }
    }
    // for diagonal right
    int n = chess.size() - c - 1;
    int maxRight = min(r, n);
    for (int i = 1; i <= maxRight; i++)
    {
        if (chess[r - i][c + i] == 1)
        {
            return 0;
        }
    }
    return 1;
}

int N_Queen(vvi &chess, int r)
{
    if (r == chess.size())
    {
        display(chess);
        return 1;
    }

    int count = 0; // initalizing the counter
    // checking for every Coloumn in that particular Row
    for (int c = 0; c < chess.size(); c++)
    {
        if (isSafe(chess, r, c))
        {
            chess[r][c] = 1;
            count += N_Queen(chess, r + 1);
            chess[r][c] = 0;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vvi chess = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << N_Queen(chess, 0);
    return 0;
}