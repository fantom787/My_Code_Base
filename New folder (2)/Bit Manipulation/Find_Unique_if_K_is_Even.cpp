// for even no of duplicate items
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int unique_element(vector<int> vec1)
{
    int ans = 0;
    for (int i = 0; i < vec1.size(); i++)
    {
        ans ^= vec1[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> vec1 = {4,3,7,8,9,4,3,7,8};
    cout<<unique_element(vec1);

    return 0;
}