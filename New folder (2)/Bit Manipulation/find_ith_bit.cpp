// find the ith bit of a number
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int ith_bit(int n,int k)
{
    return (n&(1<<k-1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<ith_bit(8,4);
      
     return 0;
}