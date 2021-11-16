// https://www.codechef.com/SPRE2021/problems/PRIMEG
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int prime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    if (prime(n))
    {
        cout << "1" << endl;
        return;
    }
    // bcz every intezer can be written as sum of 2 prime numbers
    // https://en.wikipedia.org/wiki/Goldbach%27s_conjecture
    else if (n % 2 == 0)
    {
        cout << "2" << endl;
        return;
    }
    //  if the  number ka 2 pehle wala prime hai to 2 steps lagenge bcz wo prime number + 2 will make it sum of 2 prime numbers
    else if (n % 2 != 0 && prime(n - 2))
    {
        cout << "2" << endl;
        return;
    }
    //  else make the number even by adding it and then acc to goldbach conjectur a even number can be expresssed as prime of 2numbers so total 3
    else
    {
        cout << "3" << endl;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }

    return 0;
}