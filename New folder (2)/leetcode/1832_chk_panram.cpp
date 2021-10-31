// https://leetcode.com/problems/check-if-the-sentence-is-pangram/
/*
easy hai yaar dekho 
jonsa hme letter milta hai use vector ke us place pe daal do
simple
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool checkIfPangram(string sentence)
{
    vector<int> alpha(26, 0);
    for (int i = 0; i < sentence.size(); i++)
    {
        alpha[sentence[i] - 'a']++;
    }
    for (int i = 0; i < alpha.size(); i++)
    {
        if (alpha[i] == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}