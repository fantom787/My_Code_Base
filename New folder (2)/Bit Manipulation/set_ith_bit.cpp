// set the ith bit means turn that bit to 1 if it is 1
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void set_ith_bit(int *n, int k)
{
    *n = *n | (1 << k - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 8;
    set_ith_bit(&n, 2);
    cout << n;

    return 0;
}