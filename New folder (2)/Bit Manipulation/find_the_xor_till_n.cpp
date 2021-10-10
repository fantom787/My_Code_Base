/* we have to xor till n
simple pattern hai
a%4==0 a;
a%4==1 1;
a%4==2 a+1;
a%4==3 0;
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int find_xor(int n)
{
    int ans = n % 4;
    if (ans == 0)
    {
        return n;
    }
    else if (ans == 1)
    {
        return 1;
    }
    else if (ans == 2)
    {
        return n + 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}
