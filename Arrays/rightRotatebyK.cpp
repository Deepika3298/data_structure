#include <bits/stdc++.h>
using namespace std;
//Brute force by extra array
// vector<int> rotateArray(vector<int>arr, int k) {
//     int n= arr.size();
//     k=k%n;
//     vector<int> temp;
//     for(int i=0; i<=k; i++){
//         temp.push_back(arr[i]);
//     }

//     for( int i=k+1; i<n; i++ ){
//         arr[i-(k+1)]= arr[i];
//     }

//     int j=0;
//     for(int i=k; i<n; i++){
//         arr[i]=temp[j];
//         j++;
//     }

//     return arr;
// }

// Brute force by extra variable only
// vector<int> rotateArray(vector<int>arr, int k) {
//     int p=0;
//     int n= arr.size();
//     while(p<k){
//         int first=arr[n-1];
//         for(int i=n-1; i>=0; i--){
//             arr[i] = arr[i-1];
//         }
//         arr[0]=first;
//         p++;
//     }

//     return arr;
// }

// Optimal Approach
    vector<int> rotateArray(vector<int>& nums, int k) {
        int n= nums.size();
        k=k%n;
        reverse(nums.begin(), nums.begin()+(n-k));
        
        reverse(nums.begin()+(n-k), nums.end());
        reverse(nums.begin(), nums.end());

        return nums;
    }


int main(){
    vector<int>arr, ans;
    int ele,k;
    cout<<"Enter the element in array"<<endl;
    for(int i=0; i<5; i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the number you want to rotate"<<endl;
    cin>>k;
    ans=rotateArray(arr,k);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
}