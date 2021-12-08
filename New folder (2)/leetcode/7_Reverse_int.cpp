#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int reverse(int x)
{
    long long int reversed = 0;
    int flag = 0;
    if (x < 0)
    {
        x = abs(x);
        flag = 1;
    }
    while (x > 0)
    {
        int temp = x % 10;
        reversed *= 10;
        reversed += temp;
        x /= 10;
    }
    if (flag)
    {
        reversed = -reversed;
    }
    if (reversed < INT_MIN || reversed > INT_MAX)
        return 0;
    return reversed;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}