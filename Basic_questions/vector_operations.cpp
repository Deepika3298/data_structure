#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int element;
    //for loop
    for(int i=0; i<5; i++){
        cin>>element;
        v.push_back(element);
    }
    
    //To print
    for(int i=0; i<5; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    v.insert(v.begin()+2,2);

    //for each loop
    for(int ele:v){
        cout<<ele<<" ";
    }
    cout<<endl;

    v.erase(v.end()-1);

    //while loop
    int idx=0;
    while(idx<v.size()){
        cout<<v[idx++]<<" ";
    }
    cout<<endl;
    return 0;
}