// this solution is without dp so it will take more time
// when i will learn dp i will update it
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;



int numRollsToTarget(int d, int f, int target)
{
    if (target == 0 && d == 0)
    {
        return 1;
    }
    else if (target == 0 || d == 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= f && i <= target; i++)
    {
        ans += numRollsToTarget(d - 1, f, target - i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << numRollsToTarget(2, 6, 7);
    return 0;
}