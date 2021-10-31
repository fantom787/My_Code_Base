#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int hcf(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return hcf(a % b, a);
}

int lcm(int a, int b)
{
    return a * b / hcf(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << hcf(3, 6) << endl;
    cout << lcm(3, 6) << endl;

    return 0;
}