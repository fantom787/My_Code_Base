// magic number
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int magic_number(int n)
{
    int result = 0;
    int base = 5;
    while (n != 0)
    {
        result += (n & 1) * base;
        base *= 5;
        n >>= 1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<magic_number(2);
    return 0;
}