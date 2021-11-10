// https://leetcode.com/problems/sliding-window-maximum/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
//  brute force O(n^2)
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    for (int i = 0; i < nums.size() - k + 1; i++)
    {
        int maxi = nums[i];
        for (int j = i; j < i+k; j++)
        {
            maxi = max(nums[j], maxi);
        }
        ans.push_back(maxi);
    }
    return ans;
}

/*
    dekho simple hai hme decreasing queue manitain krni hai aur uske max element ko
    apne answer array me dalte chalna hai 
    simple!!!
*/
// optimal O(n)
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> temp;
    for (int i = 0; i < nums.size(); i++)
    {
        // if our front element goes out of bound/out of window
        while (!temp.empty() && temp.front() == i - k)
        {
            temp.pop_front();
        }
        // if the element is >= the back elemenet of our queue
        while (!temp.empty() && nums[temp.back()] <= nums[i])
        {
            temp.pop_back();
        }
        temp.push_back(i);
        // if our iterator goes out of window/jb k elements pure honge queue tb jake elements push kro like k elements ki window hai to i = k-1 ho jaye to push krna start kr do
        if (i >= k - 1)
        {
            ans.push_back(nums[temp.front()]);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}