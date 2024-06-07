#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr;
    int ele;
    cout<<"Enter the element in array"<<endl;
    for(int i=0; i<5; i++){
        cin>>ele;
        arr.push_back(ele);
    }
    int largest=INT_MIN, slargest=INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        } 
        // else if(arr[i]==largest){
            
        // }
        else if( arr[i]>slargest && arr[i]!=largest){
            slargest=arr[i];
        }
    }

    cout<<largest<<slargest;
}