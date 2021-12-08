#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int jump(vector<int> &nums)
{
    int n = nums.size();
    int jumps = 0;
    int prev_jump = 0;
    int next_jump = 0;
    for (int i = 0; i <= next_jump && i < n-1; i++)
    {
        next_jump = max(next_jump, i + nums[i]);
        if (i == prev_jump)
        {
            jumps += 1;
            prev_jump = next_jump;
        }
    }

    return jumps;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {2, 3, 1, 1, 4};
    cout << jump(vec1);

    return 0;
}