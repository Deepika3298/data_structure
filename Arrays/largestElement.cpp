#include <bits/stdc++.h>
using namespace std;

//Recursive Approach- O(N)
int largestElement(vector<int>arr, int i){
    if(i==arr.size()-1) return arr[i];

    int recMax=largestElement(arr, i+1);

    return max(recMax, arr[i]); 
}

//Iterative Approach-O(N)
int largestElement(vector<int>arr){
    int a=INT_MIN;
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i]>a){
            a=arr[i];
        }
    }
    return a;
}

int main(){
    vector<int>arr;
    int ele;
    cout<<"Enter the element in array"<<endl;
    for(int i=0; i<5; i++){
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<largestElement(arr);
    cout<<largestElement(arr, 0);
}