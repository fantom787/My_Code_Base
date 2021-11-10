#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int isVowel(char c)
{
    if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
    {
        return 1;
    }
    return 0;
}

int countVowelSubstrings(string word)
{
    int counter = 0;
    for (int i = 0; i < word.size(); i++)
    {
        set<char> temp;
        for (int j = i; j < word.size(); j++)
        {
            if (isVowel(word[j]) == 0)
            {
                break;
            }
            temp.insert(word[j]);
            if (temp.size() == 5)
            {
                counter++;
            }
        }
    }
    return counter;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << countVowelSubstrings("aeiouu");

    return 0;
}