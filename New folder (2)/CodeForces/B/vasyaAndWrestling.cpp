#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

int main()
{
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    */
    long long int n;
    cin >> n;
    vector<long long int> a, b;
    long long int sum1 = 0, sum2 = 0;
    bool last = false;
    for (int i = 0; i < n; i++)
    {
        long long int x;
        cin >> x;
        if (x >= 0)
        {
            sum1 += x;
            last = false;
            a.push_back(x);
        }
        else
        {
            x *= -1;
            last = true;
            sum2 += x;
            b.push_back(x);
        }
    }
    if (sum1 > sum2)
    {
        cout << "first" << endl;
    }
    else if (sum2 > sum1)
    {
        cout << "second" << endl;
    }
    else
    {
        if (a > b)
        {
            cout << "first" << endl;
        }
        else if (b > a)
        {
            cout << "second" << endl;
        }
        else
        {
            if (last)
            {
                cout << "second" << endl;
            }
            else
            {
                cout << "first" << endl;
            }
        }
    }
    return 0;
}