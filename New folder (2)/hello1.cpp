#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define loop(o, n) for (int i = o; i < n; i++)
#define sort(a) sort(a.begin(), a.end())
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define print(a) for (auto &i : a)
#define endl "\n"
#define lower_bound(v, x) lower_bound(v.begin(), v.end(), x)
#define upper_bound(v, x) upper_bound(v.begin(), v.end(), x)
#define pb push_back

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

bool is_prime(ll n)
{
    if (n == 1)
        return (false);
    if (n == 2 || n == 3)
        return (true);
    if (n % 2 == 0 || n % 3 == 0)
        return (false);
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return (false);
    return (true);
}

int32_t main()
{
    fast

        int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> val(n);
        int m = pow(2, n);
        loop(1, m + 1)
            val[i - 1] = i;

        while (val.size() > 2)
        {
            vector<int> store;
            for (int i = 0; i < val.size(); i += 4)
            {

                cout << "? " << val[i] << " " << val[i + 2] << endl;
                fflush(stdout);
                int x;
                cin >> x;
                if (x == -1)
                    exit(0);
                if (x == 0)
                {
                    cout << "? " << val[i + 1] << " " << val[i + 3] << endl;
                    fflush(stdout);
                    cin >> x;
                    if (x == -1)
                        exit(0);
                    if (x == 1)
                        store.pb(val[i + 1]);
                    else
                        store.pb(val[i + 3]);
                }
            }
            val.clear();
            val = store;
        }
        cout << "? " << val[0] << " " << val[1] << endl;
        fflush(stdout);
        int z;
        cin >> z;
        if (z == 1)
        {
            cout << "! " << val[0] << endl;
            fflush(stdout);
        }
        else
        {
            cout << "! " << val[1] << endl;
            fflush(stdout);
        }
    }
    return 0;
}