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
    dekho bhai funda simple hai backtracking ka 
    jo cell tum visit kr rhe ho usko mark kr do aur jb
    uspe wapas jao to use unmark kr do 
    Simple!!!
*/
void mazeAllPath(string p, vvi &maze, int r, int c)
{
    //  this line is for pahuchna kha hai
    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        cout << p << endl;
        return;
    }
    //  this line keep a check on backtracking
    if (!maze[r][c])
    {
        return;
    }
    //  i am considering this block in my path
    maze[r][c] = 0;
    // for down movement
    if (r < maze.size() - 1)
    {
        mazeAllPath(p + 'D', maze, r + 1, c);
    }
    // for up movement
    if (r > 0)
    {
        mazeAllPath(p + 'U', maze, r - 1, c);
    }
    // for right movement
    if (c < maze[0].size() - 1)
    {
        mazeAllPath(p + 'R', maze, r, c + 1);
    }
    // for Left movement
    if (c > 0)
    {
        mazeAllPath(p + 'D', maze, r, c - 1);
    }
    // this line if where the funtion call will be over
    // so before the function gets removed , also remove all the changes made by  that function
    maze[r][c] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vvi maze = {{1, 1, 1},
                {1, 1, 1},
                {1, 1, 1}};
    mazeAllPath("",maze,0,0);

        return 0;
}