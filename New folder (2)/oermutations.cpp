#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void permutations(string p, string up)
{
    if (up.empty())
    {
        cout << p << endl;
        return;
    }
    char ch = up[0];
    for (int i = 0; i < p.size() + 1; i++)
    {
        string pehla = p.substr(0, i);
        string akhiri = p.substr(i);
        permutations(pehla + ch + akhiri, up.substr(1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string up = "abc";
    string p = "";
    permutations(p,up);

    return 0;
}