#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// T.C.-O(nklogk) where n is number of strings and k is max length of each string 
// S.C.- O(nk)
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string,vector<string>> mp;
    // for sorting & adding into list with same characters
    for (string s : strs)
    {
        string sortedString = s;
        sort(s.begin(), s.end());
        mp[s].push_back(sortedString);
    }
    // for pushing the vector of strings into vector.
    vector<vector<string>> ans;
    for (auto [key,vectorOfStrings] : mp)
    {
        ans.push_back(vectorOfStrings);
    }

    return ans;
}
// T.C.- O(nk)
// S.C.- O(nk)
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        // for adding frequency of elements into list
        for(string s: strs){
            string hashstring="";
            vector<int> freq(26,0);
            for(auto ch :s) freq[ch-'a']++;
            for(int i=0; i<26; i++){
                hashstring.push_back(freq[i]);
                hashstring.push_back('#');
            }
            mp[hashstring].push_back(s);
        }
        // for adding lists into ans
        vector<vector<string>> ans;
        for(auto [key,vectorOfStrings]: mp){
            ans.push_back(vectorOfStrings);
        } 
        return ans;
    }



