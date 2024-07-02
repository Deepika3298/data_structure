#include <bits/stdc++.h>
using namespace std;

// Brute approach-Time Complexity: O(N3) approx., where N = size of the array.
// Space Complexity: O(1) as we are not using any extra space.
int subarraysWithSumK(vector < int > a, int b) {
    int n=a.size();
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n ; j++){
            int xor1=0;
            for(int k=i; k<=j; k++){
                xor1= xor1^a[k];
            }
            if(xor1==b) count++;
        }
    }
    return count;
}

// Better Approach- Time Complexity: O(N2), where N = size of the array.
// Space Complexity: O(1) as we are not using any extra space.
int subarraysWithSumK(vector < int > a, int b) {
    int n=a.size();
    int count=0;
    for(int i=0; i<n; i++){
        int xor1=0;
        for(int j=i; j<n ; j++){
            xor1= xor1^a[j];
            if(xor1==b) count++;
        }
        
    }
    return count;
}

// Optimal Approach- Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array. Point to remember for unordered_map in the worst case, the searching time increases to O(N), and hence the overall time complexity increases to O(N2). 
// Space Complexity: O(N) as we are using a map data structure.
#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int n=a.size();
    int count=0;
    int xr=0;
    map<int,int> xorCount;
    xorCount[xr]++;
     int x;
    for(int i=0; i<n; i++){
       xr=xr^a[i];
       x=xr^b;
       if(xorCount.find(x)!=xorCount.end()){
           count+=xorCount[x];
       }
       xorCount[xr]++;    
    }
    return count; 
}
