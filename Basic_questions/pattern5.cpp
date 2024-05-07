#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter any number"<<endl;
    cin>>n;

    //Triangle & space
    // for(int i=1; i<=n; i++){
    //     for(int j=n-i; j>0; j--){
    //         cout<<" ";
    //     }
    //     for(int k=1; k<=i; k++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    
    //triangle reverse and space later
    // for(int i=0; i<n; i++){
    //     for(int j=n-i; j>0; j--){
    //         cout<<"*";
    //     }
    //     for(int k=0; k<=i; k++){
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }

    // triangle reverse and space first
        for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int k=n-i; k>0; k--){
            cout<<"*";
        }
        cout<<endl;
        }

    return 0;
}