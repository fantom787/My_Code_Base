#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

void display(vector<int> vec1)
{
    for (auto it : vec1)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int d;
    int sumTime;
    cin >> d >> sumTime;
    vector<int> mini(d), ans(d), diff(d);
    for (int i = 0; i < d; i++)
    {
        int x, y;
        cin >> x >> y;
        mini[i] = x;
        diff[i] = y - x;
    }
    for (int i = 0; i < d; i++)
    {
        if (sumTime < mini[i])
        {
            cout << "NO" << endl;
            return 0;
        }
        ans[i] = mini[i];
        sumTime -= mini[i];
    }
    sumTime = max(0, sumTime);
    if (sumTime)
    {
        for (int i = 0; i < d; i++)
        {
            if (sumTime <= 0)
            {
                break;
            }
            ans[i] += min(sumTime, diff[i]);
            sumTime -= diff[i];
        }
    }
    sumTime = max(0, sumTime);
    if (sumTime)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    display(ans);
    return 0;
}