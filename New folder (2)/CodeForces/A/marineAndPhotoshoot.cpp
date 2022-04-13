#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define all(s) s.begin(), s.end()
#define pb push_back
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define sz(x) (int)x.size()

// Aliases
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;

// Constants
constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

// Mathematical functions
int GCD(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int GCD_extended(int a, int b, int &x, int &y)
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int LCM(int a, int b)
{
    return ((ll)a * b) / GCD(a, b);
}

ll modpow(ll x, ll n, int m = MOD)
{
    if (x == 0 && n == 0)
        return 0; // undefined case
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

int modinv(int x, int m = MOD)
{
    return modpow(x, m - 2, m);
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            pos0.pb(i + 1);
        }
    }
    int ans = 0;
    n = sz(pos0);
    for (int i = 0; i < n - 1; i++)
    {
        int diff = pos0[i + 1] - pos0[i] - 1;
        if (diff <= 2)
        {
            ans += (2 - diff);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 1;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}
/*

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
#define cout_map(mp) for(auto& [f, s] : mp) cout << f << "  " << s << "\n";
#define fixed(n)  cout<<fixed << setprecision(n);
#define all(vec) vec.begin(),vec.end()
#define rall(vec) vec.rbegin(),vec.rend()
#define sz size()
#define PI 3.14159265359
#define pb push_back
vector<int>v;
vector<int>ans;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

}
bool ok(int md,string s,string d)
{
string t=s;
int j=0;
// cout<<d.size();
// cout<<s.size();
   for(int i=0;i<=md;i++)
   {
       t[v[i]-1]='A';
   }
   for(int i=0;i<s.size();i++)
   {

       if(t[i]!='A'&&t[i]==d[j])
         j++;
         if(j>=d.size())
            return 1;
   }
   if(j>=d.size())
    return 1;
   return 0;
}
int main() {
    FAST();
int t;cin>>t;
while(t--)
{
         int n,c1=0,c2=0;cin>>n;
         string s;
         cin>>s;

         for(int i=0;i<s.size();i++)
         {
                  if(i+1!=n&&s[i]=='0'&&s[i+1]=='0')
                  c1+=2;
                  else if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0')
                  c1++;

         }
         cout<<c1<<'\n';
}
}

Sourav, [27-03-2022 20:37]
for ( int i = 0 ; i < n -1 ; i++ ) {


        if(s[i] == '0' && s[i+1] == '0') {
            c+=2;
        }
        else if(s[i] == '0' && s[i+1] == '1' && s[i+2] == '0' && i+2 < n) {
            ++i;
            ++c;
        }

    }

    cout << c << "\n";


*/