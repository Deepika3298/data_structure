#include <bits/stdc++.h>
using namespace std;

//Brute force approach
// vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> temp;
//         for(int i=0; i<nums.size()-1; i++){
//             for(int j=i+1; j<=nums.size()-1; j++){
//                 if(nums[i]+nums[j]==target){
//                 temp.push_back(i);
//                 temp.push_back(j);
//                 } 
//             }
//         }
//         for(int i=0; i<temp.size(); i++){
//             cout<<temp[i];
//         }
// }  

// O(NlogN)- Binary Search Approach
// bool binarySearch(vector<int>& nums, int low, int high, int searchKey){
    

//     while(low<=high){
//         int mid= low + (high-low)/2;
//         if(nums[mid]==searchKey){
//             return true;
//         }
//         else if(nums[mid]<searchKey){
//             low=mid+1;
//         } else {
//             high=mid-1;
//         }
//     }
//     return false;
// }

// bool twoSum(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         for(int i=0; i<nums.size(); i++){
//             int searchKey= target-nums[i];
//             if(binarySearch(nums, i+1, nums.size()-1, searchKey)==true) return 1;
//         }
//         return 0;
// }  


//O(N)-Hashing
int twoSum(vector<int>arr, int target){
    map<int,int> mp;
    for(int i=0; i<arr.size(); i++){
        int more= target-arr[i];
        if(mp.find(more)!=mp.end()){
            return 1;
        }
        mp[arr[i]]=i;
    }
    return 0;
}
int main(){
    vector<int> arr;
    int ele;
    cout<<"Enter the array"<<endl;
    for(int i=0; i<5; i++){
        cin>>ele;
        arr.push_back(ele);
    }

    int target;
    cout<<"Enter the target number to check"<<endl;
    cin>>target;

    // twoSum(arr, target);
    cout<<twoSum(arr, target);
    return 0;
}