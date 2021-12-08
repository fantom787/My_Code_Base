// https : // leetcode.com/problems/rotate-array/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //     // easy approach make a piviot and reverse the left and right part of the piviot and then reverse the whole array
    //     void rotate(vector<int>& nums, int k) {

    //         int n = nums.size();
    //         if(n==1)
    //         {
    //             return;
    //         }
    //         // avoiding overflow
    //         while(k>n)
    //         {
    //             k-=n;
    //         }
    //         int pivot = n-k;
    //         // reversing left part
    //         int i = 0;
    //         while(i<pivot)
    //         {
    //             swap(nums[i],nums[pivot-1]);
    //             pivot--;
    //             i++;
    //         }
    //         // reversing the right part
    //         pivot = n-k;
    //         while(pivot<n)
    //         {
    //             swap(nums[pivot],nums[n-1]);
    //             pivot++;
    //             n--;
    //         }
    //         // reverse all
    //         i = 0;
    //         n = nums.size();
    //         while(i<n)
    //         {
    //             swap(nums[i],nums[n-1]);
    //             i++;
    //             n--;
    //         }

    //     }
    vector<int> rotate(vector<int> &nums, int k)
    {
        vector<int> result(nums.size());
        int left = 0, right = nums.size() - 1;
        for (int i = k % nums.size() - 1; i >= 0; i--)
        {
            result[i] = nums[right--];
        }
        for (int j = k % nums.size(); j <= nums.size() - 1; j++)
        {
            result[j] = nums[left++];
        }
        nums = result;
        return result;
    }
};
int main()
{
    return 0;
}