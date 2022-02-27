// seive of eryhoneis
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void display(vector<int> vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }
    cout << endl;
}

vector<int> seive_of_ery(int n)
{
    vector<int> test(n + 10, 1);
    vector<int> ans;
    for (int i = 2; i < sqrt(n); i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            test[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (test[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    display(seive_of_ery(10000));

    return 0;
}