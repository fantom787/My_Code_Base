// 19. [Maximum Population Year](https://leetcode.com/problems/maximum-population-year/)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int maximumPopulation(vector<vector<int>> &logs)
{
    vector<int> v(101); //2050-1950 = 101
    for (auto it : logs)
    {
        v[it[0] - 1950]++;
        v[it[1] - 1950]--;
    }
    int min_year = 0;
    int max_population = 0;
    int n = v.size();
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi += v[i];
        if (maxi > max_population)
        {
            min_year = i;
            max_population = maxi;
        }
    }

    min_year += 1950;
    return min_year;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vvi logs = {{1993, 1999}, {2000, 2010}};
    cout << maximumPopulation(logs);

    return 0;
}