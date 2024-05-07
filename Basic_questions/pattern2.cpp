#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    // Triangle star 90 degree
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<i; j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    //triangle column=row
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<i; j++){
    //         cout<<i;
    //     }
    //     cout<<endl;
    // }

    //Triangle column=count
    // int count=1;
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<i; j++){
    //         cout<<count;
    //         count++;
    //     }
    //     cout<<endl;
    // }

    //Triangle column= row & count++
    // for(int i=1; i<=n; i++){
    //     int count=i;
    //     for(int j=0; j<i; j++){
    //         cout<<count;
    //         count++;
    //     }
    //     cout<<endl;
    // }

    // Triangle column= row & count--
    for(int i=1; i<=n; i++){
        int count=i;
        for(int j=0; j<i; j++){
            cout<<count;
            count--;
        }
        cout<<endl;
    }

    return 0;
}