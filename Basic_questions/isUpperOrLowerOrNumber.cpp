#include <iostream>
using namespace std;

int main(){
    char ch;
    cout<<"Enter the character to check will it is number or UpperCase or LowerCase character"<<endl;
    cin>>ch;
    if(ch>='A' && ch<= 'Z') cout<<"Uppercase Character"<<endl;
    else if(ch>='a' && ch<= 'z') cout<<"lowercase Character"<<endl;
    else if(ch>='0' && ch<= '9') cout<<"Number"<<endl;
    else cout<<"Incorrect Input"<<endl;
    return 0;
}