#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
/*
    we have to options to print the permutation
    take 2 string 1 is processed and other is unprocessed
    if unprocessed is empty then print the processed
    warna either to take the 1st element of unprocessed or not take it
*/
void all_permutaton(string up, string pr)
{
    if (pr.empty())
    {
        cout << up << endl;
        return;
    }
    all_permutaton(up + pr[0], pr.substr(1));//taking the 1st element of unprocessed string
    all_permutaton(up, pr.substr(1));//not taking the 1st element of unprocessed string
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string up;
    string pr = "abc";
    all_permutaton(up, pr);

    return 0;
}