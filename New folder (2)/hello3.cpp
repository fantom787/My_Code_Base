/*
    Author: Ambuj Kumar(fantom787)
    If it works, don't touch it.
----------------------All Links -------------------------
 Linkedin: https://www.linkedin.com/in/ambuj-kumar-88b614203/
 Codeforces: https://codeforces.com/profile/fantom787
 Codechef: https://www.codechef.com/users/ambuj787
*/

// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

// header files
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // for pbds
#include <ext/pb_ds/tree_policy.hpp>

// namespace
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

/* ordered set*/
template <class T, class cmp = less_equal<T>>
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/* ordered map*/
template <class key, class value, class cmp = less_equal<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
/* find_by_order(k)  returns iterator to kth element starting from 0;
 * order_of_key(k) returns count of elements strictly smaller than k;*/

/* min heap*/
int main()
{
    auto cmp = [&](int a, int b) -> bool
    {
        return a > b;
    };
    set<int, decltype(cmp)> v(cmp);
    v.insert(1);
    v.insert(2);
    v.insert(3);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}