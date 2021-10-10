// to check whaether the given number is power of 2 or not
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int power_of_2(int n)
{
    return ((n) & (n - 1)) == 0 ? 1 : 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << power_of_2(256);

    return 0;
}