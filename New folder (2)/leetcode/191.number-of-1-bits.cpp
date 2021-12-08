/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
};
// @lc code=end
