#include <iostream>
using namespace std;

int main(){
    int n, sum = 0;
    cout << "Enter the number until which you want to find sum of even numbers" << endl;
    cin >> n;
    for( int i = 0; i <= n ; i++){
        if(i % 2 == 0) {
            sum = sum + i;
        }  
    }
    cout<< sum;
    return 0;
}