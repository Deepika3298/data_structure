#include <iostream>
using namespace std;

int main(){
    int n,a,b, num=1;
    cout<<"Enter the number upto which you want to find factorial"<<endl;
    cin>>n;
    
    for(int i=1; i<=n; i++){
        a=num;
        b=i;
        num=a*b;
        cout<<num<<" ";
    }
    
    return 0;
}