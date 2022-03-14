#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

void display(vector<int> vec)
{
    cout << "Displaying Vector" << endl;
    for (auto it : vec)
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
    int m, n;
    cin >> m >> n;
    vector<int> last(6);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            int time = 0;
            if (j)
            {
                time = max(last[j], last[j - 1]);
            }
            else
            {
                time = last[0];
            }
            time += x;
            last[j] = time;
        }
        cout << last[n - 1] << " ";
    }
    cout << endl;

    return 0;
}