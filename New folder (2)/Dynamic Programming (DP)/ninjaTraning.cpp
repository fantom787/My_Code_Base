#include <bits/stdc++.h>
using namespace std;
// memoization
int maxPoints(int day, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{
    if (!day)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = INT_MIN;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int temp = points[day][task] + maxPoints(day - 1, points, task, dp);
            maxi = max(maxi, temp);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    /*
    Tabulation
     vector<vector<int>>dp(n,vector<int>(4,-1));
     dp[0][1]=max(points[0][0],points[0][2]);
     dp[0][0]=max(points[0][1],points[0][2]);
     dp[0][2]=max(points[0][1],points[0][0]);
     dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));
     for(int day = 1;day<n;day++)
     {
         for(int last = 0;last<4;last++)
         {
             for(int task =0;task<3;task++)
             {
                 if(task!=last)
                 {
                     dp[day][last]=max(dp[day][last],dp[day-1][task]+points[day][task]);
                 }
             }
         }
     }
     return dp[n-1][3];
     */
    // memory optimization
    vector<int> dp(4, -1);
    vector<int> dp1(4);
    dp[1] = max(points[0][0], points[0][2]);
    dp[0] = max(points[0][1], points[0][2]);
    dp[2] = max(points[0][1], points[0][0]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    dp1[last] = max(dp1[last], dp[task] + points[day][task]);
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            dp[i] = dp1[i];
        }
    }
    return dp[3];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}