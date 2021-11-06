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
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
/*
    dekho bhai funda simple hai backtracking ka 
    jo cell tum visit kr rhe ho usko mark kr do aur jb
    uspe wapas jao to use unmark kr do 
    Simple!!!
*/
void mazeAllPath(string p, vvi &maze, int r, int c, vvi &path, int value)
{
    //  this line is for pahuchna kha hai
    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        display(path);
        cout << p << endl
             << endl;
        return;
    }
    //  this line keep a check on backtracking
    if (!maze[r][c])
    {
        return;
    }
    //  i am considering this block in my path
    maze[r][c] = 0;
    path[r][c] = value;
    // for down movement
    if (r < maze.size() - 1)
    {
        mazeAllPath(p + 'D', maze, r + 1, c, path, value + 1);
    }
    // for up movement
    if (r > 0)
    {
        mazeAllPath(p + 'U', maze, r - 1, c, path, value + 1);
    }
    // for right movement
    if (c < maze[0].size() - 1)
    {
        mazeAllPath(p + 'R', maze, r, c + 1, path, value + 1);
    }
    // for Left movement
    if (c > 0)
    {
        mazeAllPath(p + 'D', maze, r, c - 1, path, value + 1);
    }
    // this line if where the funtion call will be over
    // so before the function gets removed , also remove all the changes made by  that function
    maze[r][c] = 1;
    path[r][c] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vvi maze = {{1, 1, 1},
                {1, 1, 1},
                {1, 1, 1}};
    vvi path = {{0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}};
    mazeAllPath("", maze, 0, 0, path, 1);

    return 0;
}