#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findfib(int n)
{
    return (int)(pow(((1 + sqrt(5))/2), n) / sqrt(5));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<findfib(10);
    return 0;
}