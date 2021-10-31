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

vector<int> merge(vector<int> vec1, vector<int> vec2)
{
    int n = vec1.size(), m = vec2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
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
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans = merge(nums1, nums2);
    // display(ans);
    int mid = (nums1.size() + nums2.size()) / 2;
    if ((nums1.size() + nums2.size()) % 2 == 0)
    {
        return (((double)ans[mid] + (double)ans[mid - 1]) / 2);
    }
    else
    {
        return (double)(ans[mid]);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {1,3};
    vi vec2 = {2};
    // display(vec1);
    // display(vec2);
    // display(merge(vec2, vec1));
    cout << findMedianSortedArrays(vec1, vec2);
    return 0;
}