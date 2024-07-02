#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{

    int n = s.length();
    if (n == 0)
        return false;
    if (n == 1)
        return true;
    string m;
    m = s;
    reverse(m.begin(), m.end());
    for (int i = 0; i < n; i++)
    {
        if (s[i] == m[i])
            return false;
    }

    return true;
}
// if it contains special character Time complexity:O(n)
// Space complexity:O(1) 
bool isPalindrome(string s) {
        int n= s.length();
        if(n==0) return false;
        if(n==1) return true;
        int start=0;
        int end=n-1;
        while(start<=end){
            if(!isalnum(s[start])){
                start++; continue;
            }
            if(!isalnum(s[end])){
                end--; continue;
            }
            if(tolower(s[start])!=tolower(s[end])) return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }