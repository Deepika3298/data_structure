#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N3) & Space Complexity- O(1)
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n= arr.size();
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum=0;
            for(int K=i; K<=j; K++){
                sum=sum+arr[K];
            }
            if(sum==k) count++;
        }
    }
    return count;
}

// Time Complexity: O(N2) & Space Complexity- O(1)
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n= arr.size();
    int count=0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum=sum+arr[j];
            
            if(sum==k) count++;
        }
            
        
    }
    return count;
}

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.
// Space Complexity: O(N) as we are using a map data structure.
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n= arr.size();
    map<int,int>mp;
    mp[0]=1;
    int count=0, prefixSum=0;
    for(int i=0; i<n; i++){
        prefixSum+=arr[i];
        int remove= prefixSum-k;
        count+=mp[remove];
        mp[prefixSum]+=1;
    }
    
    return count;
}

int subarraySum(vector<int>& nums, int k) {
        
    int n = nums.size();
    int count=0;
    if(n==1 && k==1) return 1;
    if(n==1 && k==0) return 0;
    int i=0, j=0, sum=0, cnt=0;
    unordered_map<int, int>mp;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        if(sum==k)cnt++;
        if(mp.find(sum-k)!=mp.end()){
            cnt+=mp[sum-k];
        }
        mp[sum]++;
        }
        return cnt;
    }