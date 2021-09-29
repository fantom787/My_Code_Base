#include <bits/stdc++.h>
using namespace std;
#define ll long long int

template <typename T>
void display(vector<T> v1)
{
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
}
template <typename C>
vector<int> count(vector<C> v1, char c)
{
    vector<int> v2;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1.at(i) == c)
        {
            (v2).push_back(i);
        }
    }
    return v2;
}
int catch_max(vector<int> chor, vector<int> police, int k)
{
    int loopcounter = 0;
    for (int i = 0; i < police.size(); i++)
    {
        int distance = 0;
        distance = abs(chor[i] - police[i]);
        (distance <= k) ? loopcounter++ : loopcounter;
    }

    return loopcounter;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k = 2;
    vector<char> v1 = {'t', 't', 'p', 'p', 't', 'p'};
    display<char>(v1);
    vector<int> chor = count<char>(v1, 't');
    display<int>(chor);
    vector<int> police = count<char>(v1, 'p');
    display<int>(police);
    cout << catch_max(chor, police, k);

    return 0;
}