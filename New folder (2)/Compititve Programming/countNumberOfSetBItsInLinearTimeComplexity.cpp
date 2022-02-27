#include <bits/stdc++.h>
using namespace std;

#define ll long long int
/*
it can be done in O(n) TC
using dp
like u wnnna calc the number of set bits int n
then u can calc using dp via
    dp[n&(n-1)]+1
    bcz n&(n-1)has 1 bit less than the current for more info read Brian Kernighan’s Algorithm.
    so  dp[n&(n-1)] have been calculated previously
*/

void display(vector<int> vec1)
{
    for (auto it : vec1)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 1000;
    vector<int> dp(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        dp[i] = dp[i & (i - 1)] + 1;
    }
    display(dp);
    return 0;
}