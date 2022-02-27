#include <bits/stdc++.h>
using namespace std;

// binary exponentiation
long long int modPow(long long int a, long long int b, long long int m)
{
    if (!b)
    {
        return 1;
    }
    if (b & 1)
    {
        long long int t = modPow(a, (b - 1) / 2, m);
        t = (1ll * t * t) % m;
        return (1ll * t * a) % m;
    }
    else
    {
        long long int t = modPow(a, b / 2, m);
        return (1ll * t * t) % m;
    }
}


// fow negative powers also
double myPow(double x, int n, double res = 1)
{
    if (n)
    {
        if (n % 2)
        {
            if (n > 0)
                return myPow(x * x, n / 2, res * x);
            else
                return myPow(x * x, n / 2, res / x);
        }
        return myPow(x * x, n / 2, res);
    }
    else
    {
        return res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int a = 3;
    long long int b = 806166225460393;
    long long int m = 1e9 + 7;
    cout << modPow(a, b, m) << endl;
    return 0;
}