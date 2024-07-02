#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(n)
string convertString(string &str, char choice){
    if(toupper(choice)=='U'){
        for(int i=0; i<str.size(); i++){
            if(str[i]>='a' && str[i]<='z'){
                str[i]= str[i]-32;
            }
        }
    } else {
        for(int i=0; i<str.size(); i++){
            if(str[i]>='A' && str[i]<='Z'){
                str[i]= str[i]+32;
            }
        }
    }
    return str;
}

int main(){
    string str;
    cout<<"Enter the string to convert to lower case or uppercase"<<endl;
    cin>>str;

    char choice;
    cout<<"To convert to Lower Case enter 'L' or Upper case 'U'"<<endl;
    cin>>choice;
    cout<<convertString(str, choice);
}