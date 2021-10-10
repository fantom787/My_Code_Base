// find the position of the 1st set bit
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int first_bit(int n)
{
    int ans = n&(-n);
    return log2(ans)+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<first_bit(9);
      
     return 0;
}