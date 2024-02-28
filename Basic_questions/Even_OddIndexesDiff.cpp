#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int ele, diff=0, even=0, odd=0 ;
    cout<<"Enter the elements in array"<<endl;
    for(int i=0; i<5; i++){
        cin>>ele;
        v.push_back(ele);
    }
    // for(int i=0; i<v.size(); i++){
    //     if(i%2==0){
    //         sum+=v[i];
    //     }
    //     else{
    //         sum-=v[i];
    //     }
    // }

    for(int i=0; i<v.size(); i++){
        if(i%2==0){
            even=even+v[i];
            
        }
        else{
            odd=odd+v[i];
            
        }
       
    }
    diff=even-odd;
    cout<<diff;
    return 0;
}