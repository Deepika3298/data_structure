#include <bits/stdc++.h>
#include <climits>
using namespace std;

int reverse(int x) {
    int ans=0;
    while(x!=0){
      int digit=x%10;
      if( ans<INT_MIN/10 || ans> INT_MAX/10){
        return 0;
      }
      ans=(ans*10)+digit;
      x=x/10;
    } 
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    cout<<"Reversed digit is "<<reverse(n)<<endl;

    return 0;
}