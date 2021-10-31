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

void selection_sort(vi &arr, int r, int c, int max)
{
    if (r == 0)
    {
        return;
    }
    if (c < r)
    {
        if (arr[c] > arr[max])
        {
            selection_sort(arr, r, c + 1, c);
        }
        else
        {
            selection_sort(arr, r, c + 1, max);
        }
    }
    else
    {
        swap(arr[max], arr[r-1]);
        selection_sort(arr, r - 1, 0, 0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {4, 8, 3, 6, 9, 1, 4, 62, 7};
    display(vec1);
    selection_sort(vec1, vec1.size(), 0, 0);
    display(vec1);

    return 0;
}