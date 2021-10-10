// for odd number of duplicate items
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int unique_element(vector<int> vec1, int k)
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int p = 0;
        for (int j = 0; j < vec1.size(); j++)
        {
            p += (abs(vec1[j]) & (1 << i)) != 0 ? 1 : 0;
        }
        p %= k;
        result += pow(2, i) * p;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> vec1 = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 60};
    cout << unique_element(vec1, 3);

    return 0;
}