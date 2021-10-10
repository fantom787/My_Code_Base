// pascal triangle whi hai to nc0 + nc1 ... ncn krke milta tha
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int pascal_triangle(int n)
{
    return (1<<n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<pascal_triangle(5);
      
     return 0;
}