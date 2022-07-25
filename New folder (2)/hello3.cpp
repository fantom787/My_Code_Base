#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(o, n) for (int i = o; i < n; i++)
#define loop1(o, n) for (int j = o; j < n; j++)
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
const int N = 1000009;
vector<int> prime_factor[N];

/*
    std::cout << std::fixed;
       cout<<setprecision(9)<<double_variable_name<<endl;

       */

/* string s;
   if(j==0)
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
 getline(cin,s);*/

vector<int> prime, f_prime(N, 0), l_prime(N, 0);
bool fn(int a, int b)
{
    return (a < b);
}
vector<int> A(N, 1);
void generate_p()
{

    loop(2, N + 1)
    {

        if (A[i])
        {

            prime.push_back(i);

            l_prime[i] = i;
            f_prime[i] = i;
            prime_factor[i].push_back(i);
            int x = 2 * i;
            while (x < N)
            {
                prime_factor[x].push_back(i);

                if (f_prime[x] == 0)
                    f_prime[x] = i;
                l_prime[x] = i;

                A[x] = 0;
                x += i;
            }
        }
    }
}

int main()
{
    fast
        ll a,
        b, c;
    cin >> a >> b >> c;
    generate_p();
    vector<int> ans(N, 0);
    ans[1] = 1;
    for (int j = 2; j <= 1e6 + 1; j++)
    {
        int sum = 1;
        print(prime_factor[j])
        {
            int x = 0, y = j;
            while (y % i == 0)
            {
                x++;
                y /= i;
            }
            sum *= (x + 1);
        }
        ans[j] = sum;
    }
    ll final = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                int p = i * j * k;
                final += (ans[p]);
            }
        }
    }
    cout << final << endl;

    return 0;
}
