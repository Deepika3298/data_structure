#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int x;
    int element;
    cout<<"Enter the values in array"<<endl;
    for(int i=0; i<5; i++){
        cin>>element;
        v.push_back(element);
    }

    cout<<"Enter the element you want to find"<<endl;
    cin>>x;
    int idx=0;

    //from first index
    // for(int i=0; i<v.size(); i++){
    //     if(v[i]==x) idx=i;
    // }

    //from last index
    for(int i=v.size()-1; i>=0; i--){
        if(v[i]==x){
            idx=i;
            break;
        } 
        
    }
    cout<<idx;
    return 0;
}