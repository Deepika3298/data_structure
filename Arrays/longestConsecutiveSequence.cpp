#include <bits/stdc++.h>
using namespace std;

// Brute force Approach- Using Linear Search - Time complexity-O(n2) and Space Complexity-O(1)
bool ls(vector<int> a, int num){
    int n=a.size();
    for(int i=0; i<n; i++){
        if(a[i]==num){
            return true;
        }
    }
    return false;
}

int longestSuccessiveElements(vector<int>&a) {
    int n=a.size();
    int longest=1;
    for(int i=0; i<n; i++){
        int x= a[i];
        int cnt= 1;
        while(ls(a,x+1)==true){
            x+=1;
            cnt+=1;
        }
        longest= max(longest, cnt);
    }
    return longest;
}


// Better Approach- T.C.- O(nlogN)+ O(n) and S.C.- O(1)
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}


// Optimal Approach- Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
// Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).
// Space Complexity: O(N), as we are using the set data structure to solve this problem.
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;
    unordered_set<int> st;

    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }
    int longest=INT_MIN;
    //find longest sequence:
    for(auto it: st) {
        if(st.find(it-1)==st.end()){
            int x=it;
            int count=1;
            while(st.find(x+1)!= st.end()){
                x=x+1;
                count+=1;
            }
            longest = max(longest, count);
        }
        
    }
    return longest;
}