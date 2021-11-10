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
    how to add number in the large data 
    last digit me number add kr do if it has remainder then add it 
    
*/
vector<int> addToArrayForm(vector<int> &num, int k)
{
    //1. take the digits of k one by one
    //2. add the corresponding digits of num and k
    int i = num.size() - 1, carry = 0;
    vector<int> res;

    while (i >= 0 || k > 0 || carry > 0)
    {
        int digit = k % 10;
        k = k / 10;
        int sum = (i >= 0 ? num[i] : 0) + digit + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        i--;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}