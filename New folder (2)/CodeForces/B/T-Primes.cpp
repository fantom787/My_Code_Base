#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int maxN = 1e6 + 10;
bool prime[maxN];
void swad()
{
    prime[1] = true;
    for (int i = 2; i < maxN; i++)
    {
        if (!prime[i])
        {
            for (int j = 2 * i; j < maxN; j += i)
            {
                prime[j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    swad();
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        if (pow(int(sqrt(temp)),2)==temp&& (!prime[int(sqrt(temp))]))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}