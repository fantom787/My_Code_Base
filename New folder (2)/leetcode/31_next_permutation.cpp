#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

/*
    #approach:
    1. peeche se traverse kro aur jo ith number apne i+1th se chota mile whi break kr do loop
    2. peehce se fir check kro number bda than ith number found above
    3. fir dono ko swap kr do 
    4. aur i+1th se sare element ko reverse kr do

*/
void display(vi nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void next_perm(vi &nums)
{
    int n = nums.size(), k = 0, l;
    for (k = n - 1; k >= 0; k--)
    {
        if (k < n - 1 && (nums[k] < nums[k + 1]))
        {
            break;
        }
    }
    if (k == -1)
    {
        sort(all(nums));
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                swap(nums[l], nums[k]);
                break;
            }
        }
        reverse(nums.begin() + k + 1, nums.end());
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vi nums = {3, 2, 1};
    next_perm(nums);
    display(nums);

    return 0;
}