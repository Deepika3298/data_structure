#include <bits/stdc++.h>
using namespace std;

//Brute Force- T.C-O(n+d), S.C-O(d)
// vector<int> rotateArray(vector<int>arr, int k) {
//     int n= arr.size();
//     k=k%n;
//     vector<int> temp;
//     for(int i=0; i<k; i++){
//         temp.push_back(arr[i]);
//     }

//     for( int i=k; i<n; i++ ){
//         arr[i-k]= arr[i];
//     }

//     int j=0;
//     for(int i=n-k; i<n; i++){
//         arr[i]=temp[j];
//         j++;
//     }

//     return arr;
// }

// // Rotate one by one- Time Complexity: O(N * d), Auxiliary Space: O(1)
vector<int> rotateArray(vector<int>arr, int k) {
    int temp, p=1;
    int n= arr.size();
    while(p<=k){
        int last=arr[0];
        for(int i=0; i<n; i++){
            arr[i] = arr[i+1];
        }
        arr[n-1]=last;
        p++;
    }
    return arr;
}

//Another Approach T.C- O(N), S.C- O(N)
// vector<int> rotateArray(vector<int>arr, int k) {
//     int n=arr.size();
//     k=k%n;
//     for(int i=0;i<k;i++){

//         int temp=arr[0];

//         arr.erase(arr.begin());

//         arr.push_back(temp);

//     }

//     return arr;
// }

//Optimal Approach- T.C- O(2n), S.C- O(1)
// vector<int> rotateArray(vector<int>arr, int k) {
//     int n = arr.size();
    // if(n==2){
    //     reverse(arr.begin(), arr.end());
    //     return arr;
    // } else if(n>2) {
    //     k = k % n; 
        
    //     reverse(arr.begin(), arr.begin() + k);
    
    //     reverse(arr.begin() + k, arr.end());
    
    //     reverse(arr.begin(), arr.end());

    //     return arr;
    // }
// }
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