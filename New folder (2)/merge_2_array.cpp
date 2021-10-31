#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void display(vi vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }
    cout << endl;
}

vi merge(vi vec1, vi vec2)
{
    int n = vec1.size(), m = vec2.size();
    int i = 0;
    int j = 0;
    vi ans;
    while (n > 0 && m > 0)
    {
        if (vec1[i] <= vec2[j])
        {
            ans.push_back(vec1[i]);
            i++;
            n--;
        }
        else
        {
            ans.push_back(vec2[j]);
            j++;
            m--;
        }
    }
    for (int k = 0; k < n; k++)
    {
        ans.push_back(vec1[i]);
        i++;
    }
    for (int k = 0; k < m; k++)
    {
        ans.push_back(vec2[j]);
        j++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {20};
    vi vec2 = {1, 2, 3, 4, 5, 6, 7, 8};
    display(vec1);
    display(vec2);
    display(merge(vec1, vec2));
    return 0;
}