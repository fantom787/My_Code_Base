// find the nth power of the given number
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int power(int a, int b)
{
    int ans = 1;
    while (b != 0)
    {
        if (b & 1 != 0)
        {
            ans *= a;
        }
        b >>= 1;
        a *= a;
    }
    return ans;
}
// 110

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << power(3, 6);

    return 0;
}