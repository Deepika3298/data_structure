#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    int bits= sizeof(int)*8;
    int binary[bits];

    for(int i=0; i<bits; i++){
        binary[i]=n&1;
        n>>=1;
    }

    for(int i=bits-1; i>=0; i--){
        cout<<binary[i];
    }


    return 0;
}