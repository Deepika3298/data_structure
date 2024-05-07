#include <iostream>
using namespace std;

int subtractProductAndSum(int n) {
    int sum=0, m;
    int prod=1;
    while(n!=0){
        m=n%10;
        sum=sum+m;
        prod=prod*m;
        n=n/10;
    }
    int ans;
    return ans=prod-sum;
}
int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int result= subtractProductAndSum(n);
    cout<<result;

    return 0;
}