#include <bits/stdc++.h>
using namespace std;
// T.C- O(n3) & S.c.- O(1)
int subarrayWithMaxProduct(vector<int> &arr){
	int n=arr.size();
	int result = INT_MIN;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= arr[k];
            result = max(result,prod);    
        }
    }
    return result;
}
// T.C- O(n2) & S.c.- O(1)
int subarrayWithMaxProduct(vector<int> &arr){
	int n=arr.size();
	int maxProduct= arr[0];
	
	for(int i=0; i<n-1; i++){
		int product=arr[i];
		for(int j=i+1; j<n; j++){
			maxProduct=max(maxProduct,product);
			product*=arr[j];	
		}
		maxProduct=max(maxProduct,product);
	}
	
	return maxProduct;
}
// T.C-O(1) S.C.-O(1)
int subarrayWithMaxProduct(vector<int> &arr){
	int n=arr.size();
	int ans=INT_MIN;
	int pref=1, suff=1;
	for(int i=0; i<n; i++){
		if(pref==0) pref=1;
		if(suff==0) suff=1;

		pref*=arr[i];
		suff*=arr[n-i-1];
		ans=max(ans, max(pref,suff));
	}
	return ans;
}