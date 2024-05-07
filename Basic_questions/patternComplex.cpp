#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    // Star pyramid
    // for(int i=1; i<=n; i++){
    //     for(int j=n-i; j>0; j--){
    //         cout<<" ";
    //     }
    //     for(int k=1; k<=i; k++){
    //         cout<<"* ";
    //     }
    //     for(int j=n-i; j>0; j--){
    //         cout<<" ";
    //     }cout<<endl;

    // }

    // Counting pyramid
    // for(int i=1; i<=n; i++){
    //     for(int j=n-i; j>0; j--){
    //         cout<<" ";
    //     }
    //     int count=1;
    //     for(int k=1; k<=i; k++){
    //         cout<<count;
    //         count++;
    //     }
    //     int count1=i-1;
    //     for(int k=1; k<i; k++){
    //         cout<<count1;
    //         count1--;
    //     }
    //     for(int j=n-i+1; j>0; j--){
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }

    // Counting and Star pyramid
    // for(int i=0; i<n; i++){
    //     int count=1;
    //     for(int j=n-i; j>0; j--){
    //         cout<<count;
    //         count++;
    //     }
        
    //     int star=i*2;
    //     while(star){
    //         cout<<"*";
    //         star--;
    //     }
    //     int count1=n-i;
    //     for(int j=1; j<=n-i; j++){
    //         cout<<count1;
    //         count1--;
    //     }cout<<endl;
    // }

    // Diamond Pattern
    for(int i=1; i<=n; i++){
        for(int j=n-i; j>0; j--){
            cout<<" ";
        }
        for(int k=1; k<=i; k++){
            cout<<"* ";
        }
        for(int j=n-i; j>0; j--){
            cout<<" ";
        }cout<<endl;

    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<" ";
        }
        for(int k=i; k<=n-1; k++){
            cout<<"* ";
        }
        for(int j=1; j<=i; j++){
            cout<<" ";
        }cout<<endl;
    }
    
    return 0;
}