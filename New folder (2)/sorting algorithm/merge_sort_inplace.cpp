#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

void display(vi vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }
    cout << endl;
}

void merge(vi &vec1, int low, int mid, int high)
{
    vi arr1(vec1.size());
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (vec1[i] < vec1[j])
        {
            arr1[k] = vec1[i];
            i++;
            k++;
        }
        else
        {
            arr1[k] = vec1[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        arr1[k] = vec1[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        arr1[k] = vec1[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        vec1[i] = arr1[i];
    }
}

void merge_sort_algo(vi &vec1, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort_algo(vec1, low, mid);
        merge_sort_algo(vec1, mid + 1, high);
        merge(vec1, low, mid, high);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {10, 5, 9, 2, 4, 82, 4, 82, 8};
    display(vec1);
    merge_sort_algo(vec1, 0, vec1.size() - 1);
    display(vec1);
    return 0;
}