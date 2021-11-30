// https://leetcode.com/problems/add-to-array-form-of-integer/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vector<int> addToArrayForm(vector<int> &num, int k)
{
    vector<int> ans;
    int i = num.size() - 1;
    int carry = 0;
    while (i >= 0 || k > 0 || carry > 0)
    {
        int last_digit = k % 10;
        k /= 10;
        int sum;
        if (i >= 0)
        {
            sum = num[i];
        }
        else
        {
            sum = 0;
        }
        sum += last_digit + carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
        i--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}