#include <bits/stdc++.h>
using namespace std;

//Brute force Approch
// bool isPowerOfTwo(int n) {
//         int ans=1;
//         for( int i=0; i<=30; i++){
//             if(ans==n) return true;
            
//             if(ans < INT_MAX/2)
//             ans=ans*2;
//         }
//         return false;
// }

//time complexity- log(n) Modulo and divide
// bool isPowerOfTwo(int n){
//     if (n == 0)
//         return 0;
//     while (n != 1) { //LCM format
//         if (n % 2 != 0)
//             return 0;
//         n = n / 2;
//     }
//     return 1;
// }

// bool isPowerOfTwo(int n){ //Set Bit
//     int count=0;
//     if (n == 0)
//          return 0;
//     while(n!=0){
//         if((n&1)==1)
//             count++;
//         n=n>>1;    
//     } 
//     if(count==1) return true;
//     else return false;    
// }

//log(1)
bool isPowerOfTwo(int n){
    if(n<0) return false;

    return n && (!(n&(n-1))); 
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<isPowerOfTwo(n)<<endl;
    return 0;
}