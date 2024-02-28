#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int x, count=0, element;;

    cout<<"Enter the elements"<<endl;
    for(int i=0; i<10; i++){
        cin>>element;
        v.push_back(element);
    }

    cout<<"Enter the element you want to count"<<endl;
    cin>>x;

    for(int i=0; i<v.size(); i++){
        if(v[i]==x) count++;
    }
    cout<<count;

    return 0;
}