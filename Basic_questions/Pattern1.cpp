#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    //row=column
    // for(int i=0; i<n; i++){
    //     for(int i=0; i<n; i++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    //column=rowNo
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<i;
    //     }
    //     cout<<endl;
    // }

    //column= 1 to n from start
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }

    // column= n to 1
    // for(int i=1; i<=n; i++){
    //     for(int j=n; j>=1; j--){
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }
    // return 0;

    //column= count
    int count=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<count;
            count++;
        }
        cout<<endl;
    }
    return 0;
}