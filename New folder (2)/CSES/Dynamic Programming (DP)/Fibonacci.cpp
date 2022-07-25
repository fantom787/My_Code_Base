#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

/* fib by memoization--> its top to bottom recursion
time complexity - O(n)
space complexity - O(n)[for recurrsion ] + O(n)[for dp array]
int fib(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}
*/

// dp memory optimization
ll fib(int n)
{
    ll  prev1 = 1, prev2 = 0, curr;
    for (int i = 0; i < n - 1; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 500;
    vector<int> dp(n + 1, -1);
    // cout << fib(n,dp);

    /*
     fib by tabulation --> its bottom up i.e Base case to the recquired answer
     step 1 --> initalize the dp array and write the base cases
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    */

    cout << fib(50);

    return 0;
}