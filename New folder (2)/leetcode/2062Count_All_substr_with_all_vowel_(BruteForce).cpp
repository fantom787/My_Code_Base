#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
//  Function that checks that the given character is a vowel or not
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
    int counter = 0; // initalize the counter with 0
    for (int i = 0; i < word.size(); i++)
    {
        set<char> temp;// set initalized outside the for loop so as to avoid the persitance of the pervious iteration values in the set
        for (int j = i; j < word.size(); j++)
        {
            //  if the jth charcter is not a vowel then break the loop
            if (isVowel(word[j]) == 0)
            {
                break;
            }
            // else insert the char value in the SET
            temp.insert(word[j]);
            //  if size == 5 (as there are 5 vowels in English alphabet)  then increase the counter by 1
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

    return 0;
}