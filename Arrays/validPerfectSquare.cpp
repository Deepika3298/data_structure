#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log(x)) & Auxiliary Space: O(1)
// bool checkValidPerfectSqr(long long n){
//     if(n>=0){
//         long long sq= sqrt(n);
//         return (sq*sq==n);
//     }
//     return -1;
// }

// Time Complexity : O(sqrt(n)) & Auxiliary space: O(1)
// bool checkValidPerfectSqr(long long n){
//     if((ceil((double)sqrt(n)))==(floor((double)sqrt(n)))){
        
//         return true;
//     }
//     return false;
// }

bool checkValidPerfectSqr(long long n){
    if(n<=1 && n>=0) return true;
    int left=1, right=n;
    while(left<=right){
        long long mid= left + (right-left)/2;
        long long square= mid*mid;
        if(square==n) return true;
        else if(square>n) left= mid+1;
        else right= mid-1;
    }
    return false;
}


int main(){
    long long n;
    cout<<"Enter the number to check if it is valid perfect square"<<endl;
    cin>>n;

    cout<<checkValidPerfectSqr(n);
    return 0;
}