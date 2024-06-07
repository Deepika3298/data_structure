#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N2), where N = size of the array+1.
// Reason: In the worst case i.e. if the missing number is N itself, the outer loop will run for N times, and for every single number the inner loop will also run for approximately N times. So, the total time complexity will be O(N2).
// Space Complexity: O(1)  as we are not using any extra space.
// int missingNumber(vector<int>&a, int N){
//     for( int i=1; i<=N; i++){
//           int flag=0;
//           for( int j=0; j<N-1; j++){
//             if(a[j]==i){
//                 flag=1;
//                 break;
//             }
//           }
//           if(flag==0) return i;
//     }
//     return -1;
// }



// Hash map-Time Complexity: O(N) + O(N) ~ O(2*N),  where N = size of the array+1.
// Reason: For storing the frequencies in the hash array, the program takes O(N) time complexity and for checking the frequencies in the second step again O(N) is required. 
// So, the total time complexity is O(N) + O(N).
// Space Complexity: O(N), where N = size of the array+1. Here we are using an extra hash array of size N+1.
// int missingNumber(vector<int>&a, int N) {
//     int hash[N+1]={0};
//     for (int i = 0; i <N-1 ; i++) {
//       hash[a[i]]++;
//     }
//     for (int i = 1; i <=N; i++){
//         if(hash[i]==0) return i;
//     }
//     return -1;
// }

// Summation Approach:Time Complexity- O(n) & Space complexity- O(1)
// int missingNumber(vector<int>&a, int N) {
//     int expectedSum = (N*(N+1))/2;
//     int actualSum = 0;
//     for(int i = 0; i < a.size(); i++) {
//         actualSum+=a[i];
//     }
//     return expectedSum-actualSum;
// }

// XOR Approach:Time Complexity: O(N) & Space complexity O(1)
int missingNumber(vector<int>&a, int N) {
    int xor1=0, xor2=0;
    for(int i=0; i<N-1; i++){
      xor2= xor2^a[i];
      xor1=xor1^(i+1);
    }
    xor1=xor1^N;

    return (xor1^xor2);
}

// Xor approach for leetcode
int missingNumber(vector<int>& nums) {
        int ans=0;
        int n= nums.size();
        for(int i=1; i<=n; i++){
            ans= ans^i;
        }
        for(int i=0; i<n; i++){
            ans= ans^nums[i];
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
    cout<<missingNumber(arr,n);
    
    return 0;
}