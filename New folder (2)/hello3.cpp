#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
/*  Function that checks that the given character is a vowel or not*/
int isVowel(char c)
{
    if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
    {

        return 1;
    }
    return 0;
}
/* this function returns all strings with k no of vowels*/
int countAtMost(string s, int k)
{
    int n = s.size();
    int count = 0;/* keeps the count of total number of string of Atmost K size(number of vowel)*/
    /* marks the starting point of the string this pointer helps us to maintain Atmost K length(number of vowel) of substring */
    int i = 0;
    /*
        reason for choosing Unordered_map
            1. we need to keep count on the number of same vowels
            2. we could have used map bt here no requirement of orderness 
            3. map is based on tree data structure and unordered map uses hashing so it reduces its search time complexity from O(logN) to O(1)
    */
    unordered_map<char, int> vowelMap;
    for (int j = 0; j < n; j++)
    {
        /* if the jth char is not a vowel then ith pointer is moved as before it we have calculated all the substring containing vowel of atmost k size(number of vowel)
        */
        if (isVowel(s[j])==0)
        {
            /* and map is cleard so that previous values cannot affect the new results*/
            vowelMap.clear();
            i = j + 1;
            continue;
        }
        /*  else it is inserted in the map and its count is incresaed with 1*/
        vowelMap[s[j]]++;
        /*  if the number of vowels in the map is more than k then  remove it */
        while (vowelMap.size() > k)
        {
            /*the ith vowel's count is decreased */
            vowelMap[s[i]]--;
            /* if the count becomes 0 then pls erase it from the map so that it does not tamper the size of map*/
            if (vowelMap[s[i]] == 0)
            {
                vowelMap.erase(s[i]);
            }
            i++;
        }
        /*
        for size 3 substring the total number of substring would be 3 
        for eg :-
        aei
        there would be substring aei, ie,ae ==3
        and rest we have counted in previous iteration
        for more explanation pls watch the video
        https://www.youtube.com/watch?v=q9AaGR5C3b4
        */
        count += (j - i + 1);
    }
    return count;
}

int countVowelSubstrings(string word)
{
    /*
    total number of substring containing only five vowels =  all substring containing atmost five vowel - all substring containng atmost four vowels
    */
    return countAtMost(word, 5) - countAtMost(word, 4);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}