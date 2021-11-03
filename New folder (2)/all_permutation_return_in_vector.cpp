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

void display(vector<string> vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }
    cout << endl;
}

vector<string> all_permutation(string up, string pr, vector<string> ans)
{
    if (pr.empty())
    {
        vector<string> temp;
        temp.push_back(up);
        return temp;
    }
    vector<string> left = all_permutation(up + pr[0], pr.substr(1), ans);
    vector<string> right = all_permutation(up, pr.substr(1), ans);
    ans.insert(ans.begin(), all(left));
    ans.insert(ans.end(), all(right));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string up;
    string pr = "abc";
    vector<string> ans;
    display(all_permutation(up, pr, ans));

    return 0;
}