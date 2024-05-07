#include <iostream>
using namespace std;

int bitwiseComplement(int n) {
    int m = n, ans = 0;
    int mask = 0;
    if(n==0) return 1;

    while(m != 0){
        mask = ( mask << 1 ) | 1;
        m=m>>1;
    }
    ans=(~n) & mask;
    return ans ;
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<"Compliment of number is "<<bitwiseComplement(n)<<endl;
}