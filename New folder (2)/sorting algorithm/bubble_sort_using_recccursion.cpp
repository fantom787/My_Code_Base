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

void bubble_sort(vi &arr, int r , int c = 0)
{
    if (r == 0)
    {
        return;
    }
    if (r > c)
    {
        if (arr[c] > arr[c + 1])
        {
            swap(arr[c], arr[c + 1]);
        }
        bubble_sort(arr, r, c + 1);
    }
    bubble_sort(arr, r - 1, 0);
}
//  create a doubly linked list inset delete and traverse
// deleterion in the begining
// insertion at a particular position

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {4, 8, 3, 6, 9, 1, 4, 62, 7};
    display(vec1);
    bubble_sort(vec1, vec1.size() - 1);
    display(vec1);

    return 0;
}