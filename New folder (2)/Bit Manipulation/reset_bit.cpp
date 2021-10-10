// reset bit means 1 hai to 0 kr do
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void resetabit(int &n, int k)
{
    n &= ~(1 << k - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 10;
    resetabit(n,2);
    cout<<n;


    return 0;
}