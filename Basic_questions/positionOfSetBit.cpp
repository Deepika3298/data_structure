#include <iostream>
using namespace std;

//Optimal Approach-O(1)
int findPosition(int N) {
        int pos=1;
       if (N==0 || (N & (N-1))!=0 ) return -1;
    
        while(N>0){
            if(N & 1) return pos;
            
            N=N>>1;
            pos++;
        }
}


int main(){
    int n;
    
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<findPosition(n)<<endl;
}