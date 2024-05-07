#include <iostream>
using namespace std;

int main(){
    string binary;
    cout<<"Enter the binary Number"<<endl;
    cin>>binary;
    int decimal=0;
    int power=1;

    for(int i=binary.length()-1; i>=0; i--){
        if(binary[i]=='1'){
            decimal+=power;
        }
        power*=2;
    }
    cout<<decimal;

    return 0;
}