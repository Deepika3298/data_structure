#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int ele,flag=0;
    cout<<"Enter the elements in array"<<endl;
    for(int i=0; i<10; i++){
        cin>>ele;
        v.push_back(ele);
    }

    for(int i=1; i<v.size();i++){
        if(v[i]<v[i-1]){
            flag=1;
            break;
        }    
    }

    if(flag==0) cout<<"Array is Sorted"<<endl;
    else cout<<"Array is not Sorted"<<endl;
    return 0;
}