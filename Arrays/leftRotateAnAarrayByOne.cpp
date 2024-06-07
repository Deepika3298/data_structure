#include <bits/stdc++.h>
using namespace std;

// T.C.- O(n) 
//  S.C-O(n)used in algorithm & extra Space- O(n)
// vector<int> leftRotateByOne(vector<int>&arr, int n){
//     int temp=0;
//     for(int i=1; i<n; i++){
//         temp=arr[i];
//         arr[i]=arr[i-1];
//         arr[i-1]=temp;
//     }
//     return arr;
// }

//Better than previous one
vector<int> leftRotateByOne(vector<int>&arr, int n){
    int temp= arr[0];
    for(int i=1; i<n; i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]= temp;
    return arr;
}

int main(){
    vector<int>arr;
    int ele;
    cout<<"Enter the element in array"<<endl;
    for(int i=0; i<6; i++){
        cin>>ele;
        arr.push_back(ele);
    }
    int n=arr.size();
    vector<int> ans=leftRotateByOne(arr,n);

    for(int i=0; i<ans.size() ; i++){
        cout<< arr[i];
    }
    
    return 0;
}