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
    for (auto it : vec1)
    {
        cout << it << " ";
    }
    cout << endl;
}

inline int binary_search(vector<int> arr, int target)
{
    int l = 0;
    int n = arr.size();
    int h = n - 1;
    int mid = l + (h - l) / 2;
    while (l <= h)
    {
        if (arr[mid] > target)
        {
            h = mid - 1;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            return mid;
        }
        mid = l + (h - l) / 2;
    }
    return -1;
}
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ans;
    int n = numbers.size();
    for (int i = 0; i < n; i++)
    {
        // cout << "i am in for loop"
            //  << " ";
        int req = target - numbers[i];
        int result =  binary_search(numbers, req);
        // cout << "result " << result << endl;
        if (result != -1)
        {
            if (i == result)
            {
                if (numbers[result + 1] == req)
                {
                    result++;
                }
                else if (numbers[result - 1] == req)
                {
                    result--;
                }
            }
            ans.push_back(i + 1);
            ans.push_back(result + 1);
            break;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {2, 7, 11, 15};
    // vi vec2 = twoSum(vec1, 9);
    display(vec1);
    display(twoSum(vec1, 9));
    // cout<<vec2[0]<<" "<<vec2[1];

    return 0;
}