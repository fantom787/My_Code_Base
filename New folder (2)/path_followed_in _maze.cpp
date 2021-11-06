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
counts the number of ways to reach from 0,0 to 3,3
*/
int count(int x, int y)
{
    if (x == 1 || y == 1)
    {
        return 1;
    }
    int left = count(x - 1, y);
    int right = count(x, y - 1);
    return left + right;
}

void path(int x, int y, string up = "")
{
    if (x == 1 && y == 1)
    {
        cout << up << endl;
        return;
    }
    if (x > 1)
    {
        path(x - 1, y, up + "R");
    }
    if (y > 1)
    {
        path(x, y - 1, up + "D");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << count(3, 3);
    path(3,3);

    return 0;
}