#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int securitiesBuying(int z, vector<int> security_value)
{
    int tempz;
    int maxi = INT_MIN;
    for (int i = 0; i < security_value.size(); i++)
    {
        int tempi = i;
        tempz = z;
        int loop_counter = 0;
        while (tempz > 0 && i < security_value.size())
        {
            int temp_lc = 0;
            temp_lc = tempz / security_value[i];
            if (temp_lc > i + 1)
            {
                temp_lc = i + 1;
                loop_counter += i + 1;
                tempz -= security_value[i] * temp_lc;
            }
            else
            {
                loop_counter += temp_lc;
                tempz -= security_value[i] * temp_lc;
            }
            i++;
        }
        maxi = max(maxi, loop_counter);
        i = tempi;
    }
    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> nums = {49, 34, 2, 5, 17, 28, 44, 44, 18, 36, 31, 31, 27, 7, 8, 46, 31, 18, 32, 21};
    cout << securitiesBuying(497, nums);

    return 0;
}