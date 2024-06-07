#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N) & Space complexity O(1)
int consecutiveOnes(vector<int>& arr){
    int count=1;
    int maximum=-1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==1 && arr[i+1]==1)
        count++;
        else 
        count=1;

        maximum=max(maximum, count);
    }
    return maximum;
}

int main(){
    vector<int>arr;
    int ele;
    cout<<"Enter the element in array"<<endl;
    for(int i=0; i<5; i++){
        cin>>ele;
        arr.push_back(ele);
    }
   
    cout<<consecutiveOnes(arr);
    
    return 0;
}