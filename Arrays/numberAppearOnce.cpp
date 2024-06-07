#include <bits/stdc++.h>
using namespace std;

// Brute Approach- Time complexity- O(n sq) and space complexity- O(1)
// int numberAappearOnce(vector<int> arr){
//     int n=arr.size();
//     for(int i=0; i<n; i++){
//         int num= arr[i];
//         int count=0;
//         for(int j=0; j<n; j++){
//             if(arr[j]==num){
//                 count++;
//             }
//         }
//         if(count==1) return num;
//     }

// }
// Time Complexity: O(n)&Space Complexity: O(n) (worst case), O(min(n, k)) (average)
int numberAappearOnce(vector<int> &arr, int n){
		unordered_map<int,int> mp;
		for( int i=0; i< arr.size(); i++){
			if(mp.find(arr[i])!= mp.end()){
				mp[arr[i]]++;
			} else {
				mp[arr[i]]=1;
			}
		}
		for( auto ele: mp){
			if(ele.second==1) return ele.first;
		}
    
}
// Time Complexity: O(N), where N = size of the array.& Space Complexity: O(1) as we are not using any extra space.
int numberAappearOnc(vector<int> &arr){
		int ans=0;
        for(int i=0; i<arr.size(); i++){
            ans= ans^arr[i];
        }
        return ans;
}
int main(){
    vector<int>arr;
    int ele;
    cout<<"Enter the element in array"<<endl;
    for(int i=0; i<5; i++){
        cin>>ele;
        arr.push_back(ele);
    }
    int n=arr.size();
    cout<<numberAappearOnce(arr,n);
    
    return 0;
}