//no of set bits
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int setbits(int n)
{
    int ans = 0;
    while (n>0)
    {
        ans++;
        n-=(n&(-n));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setbits(10);
      
     return 0;
}