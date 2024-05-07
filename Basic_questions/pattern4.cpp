#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter any number"<<endl;
    cin>>n;

    //Triangle alphabet
    // char c='A';
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<i; j++){
    //         cout<<c;
    //     }
    //     cout<<endl;
    //     c=c+1;
    // }

    //Triangle alphabet continue
    // char c='A';
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<i; j++){
    //         cout<<c;
    //         c=c+1;
    //     }
    //     cout<<endl;    
    // }

    // Triangle alphabet continue according to  row
    // for(int i=0; i<n; i++){
    //     char c='A'+i;
    //     for(int j=0; j<=i; j++){
    //         cout<<c;
    //         c=c+1;
    //     }
    //     cout<<endl;    
    // }

    //Triangle Alphabet reverse
    for(int i=1; i<=n; i++){
        char c='A'+n-i;
        for(int j=1; j<=i; j++){
            cout<<c;
            c=c+1;
        }
        cout<<endl;    
    }
    return 0;
}