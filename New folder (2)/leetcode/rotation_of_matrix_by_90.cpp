// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void display(vvi vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = 0; j < vec1[0].size(); j++)
        {
            cout << vec1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void rotation(vvi &vec1)
{
    vvi vec2 = vec1;
    // cout<<vec2.size()<<" "<<vec2[0].size();
    int n = vec1.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vec2[j][n - 1 - i] = vec1[i][j];
        }
    }
    vec1 = vec2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vvi mat = {{1, 0, 1}, {0, 1, 0}, {0, 0, 1}};
    display(mat);
    // reverse(mat.begin(), mat.end());
    rotation(mat);
    display(mat);
    return 0;
}