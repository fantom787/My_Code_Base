// check krna hai ki given no 2ki power ka hai ki nhi
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int chk_2_power(int n)
{
    int ans = (n&(n-1))==0?1:0;
    return ans;
}
// 1000
// 0111

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<chk_2_power(8);
      
     return 0;
}