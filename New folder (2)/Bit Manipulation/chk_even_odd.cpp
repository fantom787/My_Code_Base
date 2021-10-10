// chk even odd
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int chk_even_odd(int n)
{
    return (n&1==1?0:1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<chk_even_odd(2);
      
     return 0;
}