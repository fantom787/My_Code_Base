#include <bits/stdc++.h>
using namespace std;
/*
int cntOnes(int n)
{
    int ans = 0;
    while (n)
    {
        if (n & 1)
            ans++;
        n >>= 1;
    }
    return ans;
}
*/
// Brian Kernighan’s Algorithm.
/*

Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit. 
for example : 
10 in binary is 00001010 
9 in binary is 00001001 
8 in binary is 00001000 
7 in binary is 00000111 
So if we subtract a number by 1 and do it bitwise & with itself (n & (n-1)), we unset the rightmost set bit. If we do n & (n-1) in a loop and count the number of times the loop executes, we get the set bit count. 
The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer. .

*/
int cntOnes(int n)
{
    int ans = 0;
    while (n)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(m + 1);
    for (int i = 0; i < m + 1; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (cntOnes(arr[i] ^ arr[m]) <= k)
            ans++;
    }

    cout << ans << endl;
    return 0;
}