#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
        int n= s.size();
        int i=0, j=n-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
}

