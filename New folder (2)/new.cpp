#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int linear_search(vector<int> vec1, int target)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] == target)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> vec1 = {7,6,8,2,9,3,4};
    cout<<linear_search(vec1,4);

    return 0;
}