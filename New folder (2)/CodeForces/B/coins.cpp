#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

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
    int n;
    cin >> n;
    vector<int> ans;
    ans.push_back(n);
    while (n > 1)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (!(n % i))
            {
                n = i;
                ans.push_back(i);
                n = i;
                break;
            }
        }
    }
    if (ans.back() != 1)
    {
        ans.push_back(1);
    }
    display(ans);

    return 0;
}