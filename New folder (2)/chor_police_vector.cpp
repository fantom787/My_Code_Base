#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> v1)
{
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
}
vector<int> count(vector<int> v1, char c)
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
        if (distance <= k)
        {
            loopcounter++;
        }
    }

    return loopcounter;
}
int main()
{
    int k = 2;
    vector<int> v1 = {'t', 't', 'p', 'p', 't', 'p'};
    vector<int> police = count(v1, 'p');
    vector<int> chor = count(v1, 't');
    display(v1);
    display(police);
    display(chor);
    cout << catch_max(chor, police, k) << endl;
    return 0;
}