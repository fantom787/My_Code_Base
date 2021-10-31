//  newton rapson method
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

double newton_rapson(int n, float precison)
{
    double x = n;
    double root;
    while (1)
    {
        root = 0.5 * (x + (n / x));
        if (abs(x - root) < precison)
        {
            break;
        }
        x = root;
    }
    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << newton_rapson(50, 0.001);

    return 0;
}