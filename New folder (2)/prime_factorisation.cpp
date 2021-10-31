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

vector<int> prime_factor(int n)
{
    vector<int> factor;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                factor.push_back(i);
                n /= i;
            }
        }
    }
    if (n != 1)
    {
        factor.push_back(n);
    }
    return factor;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    display(prime_factor(24));

    return 0;
}