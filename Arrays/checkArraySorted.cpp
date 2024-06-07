#include <bits/stdc++.h>
using namespace std;

//Recursive Approach-Time Complexity: O(n) 
// Auxiliary Space: O(n) for Recursion Call Stack.
// int checkArraySorted(vector<int> arr, int n){
//     if(n==0 || n==1) return true;

//     return arr[n-1]>=arr[n-2] && checkArraySorted(arr, n-1);
// }

//Iterative Approach-Time Complexity: O(n) 
// Auxiliary Space: O(1)
// int checkArraySorted(vector<int> arr, int n){
//     for(int i=1; i<=n-1; i++ ){
//         if(arr[i-1]<=arr[i]){
            
//         } else {
//             return false;
//         }
//     }
//     return true;
// }

//2-pointer ApproachTime complexity : O(n/2) which is O(n) linear time.
// Space complexity : O(1)
int checkArraySorted(vector<int> arr, int n){
    int left = 0, right = n - 1;
    while (left < right) {
        if (arr[left] > arr[right]) {
            return false;
        } else if (left != 0 && right != n - 1 && (arr[left] < arr[left - 1] || arr[right] > arr[right + 1])) {
                return false;
            }
        
        left++;
        right--;
    }
    return true;
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
    cout<<checkArraySorted(arr,n);
    
    return 0;
}