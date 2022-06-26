#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// to find element on xth index --> *a.find_by_order(x);
// to find the no of elements smaller than x - > a.order_of_key(x);
int main()
{
    pbds a;
    a.insert(1);
    a.insert(10);
    a.insert(5);
    a.insert(7);
    a.insert(9);
    a.insert(10);

    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
    // cout << "Element at 0th index : " << *a.find_by_order(0) << endl;
    // cout << "Element at 1th  index : " << *a.find_by_order(1) << endl;
    // cout << "Element at 2nd index : " << *a.find_by_order(2) << endl;
    // cout << "Element at 3rd  index : " << *a.find_by_order(3) << endl;

    cout << a.order_of_key(11) << endl;

    return 0;
}