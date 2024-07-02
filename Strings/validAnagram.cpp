#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N * logN), For sorting.
// Auxiliary Space: O(1)
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
            return false;
    }
    return true;
}

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    const int No_of_Chars = 256;
    int count1[No_of_Chars] = {0};
    int count2[No_of_Chars] = {0};

    for (int i = 0; i <= s[i] && t[i]; i++)
    {
        count1[s[i]]++;
        count2[t[i]]++;
    }

    for (int i = 0; i < No_of_Chars; i++)
    {
        if (count1[i] != count2[i])
            return false;
    }

    return true;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    const int No_of_Chars = 256; // Number of possible characters in extended ASCII
    int count[No_of_Chars] = {0};

    // Increment counts for characters in s and decrement for characters in t
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
        count[t[i]]--;
    }

    // If all counts are zero, then s and t are anagrams
    for (int i = 0; i < No_of_Chars; i++)
    {
        if (count[i] != 0)
            return false;
    }

    return true;
}
// Time Complexity: O(N) & Space complexity-O(N)
bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            if(mp.find(t[i])!=mp.end()){
                mp[t[i]]--;
            }else {
                return false;
            }
        }
        for(auto el:mp){
            if(el.second!=0) return false;
        }
        return true;
    }