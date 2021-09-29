#include <bits/stdc++.h>
using namespace std;
class testcase
{
public:
    int n;
    int x;
    vector<int> v1;
};
int binarysearch(vector<int> v1, int element)
{
    int low = 0, high = v1.size(), mid;
    if (element == v1[low])
    {
        return low;
    }
    if (element == v1[high])
    {
        return high;
    }
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (element == v1[mid])
        {
            return 1;
        }
        if (v1[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int repetitions(vector<int> v1)
{
    int n = v1.size();
    int max1 = 0;
    for (int i = 0; i < n; i++)
    {
        max1 = max(max1, v1[i]);
    }
    int arr1[max1];
    for (int i = 0; i < max1; i++)
    {
        arr1[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        arr1[v1[i] - 1] += 1;
    }
    int max2 = 0;
    for (int i = 0; i < max1; i++)
    {
        max2 = max(max2, arr1[i]);
    }
    return max2;
}

int main()
{
    int n, temp;
    cin >> n;
    testcase t1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> t1[i].n;
        cin >> t1[i].x;
        for (int j = 0; j < t1[i].n; j++)
        {
            cin >> temp;
            t1[i].v1.push_back(temp);
        }
    }
    int max_equal_int = 0, min_operation = 0, temp2;
    for (int i = 0; i < n; i++)
    {
        max_equal_int = 0, min_operation = 0;
        max_equal_int = repetitions(t1[i].v1);
        for (int j = 0; j < t1[i].n; j++)
        {
            temp2 = t1[i].v1[j] ^ t1[i].x;
            if (binarysearch(t1[i].v1, temp2) == 1)
            {
                t1[i].v1[j] = temp2;
                max_equal_int += 1;
                min_operation += 1;
            }
            else
            {
                continue;
            }
        }
        cout << max_equal_int << " ";
        cout << min_operation << endl;
    }

    return 0;
}