#include <bits/stdc++.h>
using namespace std;
// Variety1- Coding NINjas Alternate numbers 
// Brute force Approach
vector<int> alternateNumbers(vector<int>&a) {
    int n=a.size();
   vector<int> arr1; 
   vector<int> arr2; 
   
   for(int i=0; i<n; i++){
    if(a[i]>0) arr1.push_back(a[i]);
    if(a[i]<0) arr2.push_back(a[i]);
   }

   for(int i=0; i<n/2; i++){
    a[2*i]=arr1[i];
    a[2*i+1]=arr2[i];
   }
   return a;
}


// Optimal Approach Time & Space complexity- O(N)
vector<int> alternateNumbers(vector<int>&a) {
    int n=a.size();
   vector<int> arr(n,0); 
   int i=0, j=1;
   for(int k=0; k<n; k++){
       if(a[k]>0){
           arr[i]=a[k];
           i+=2;
       }
       if(a[k]<0){
           arr[j]=a[k];
           j+=2;
       }
   }
   return arr;
}

// Variety-2 Coding Ninjas Rearrange alternatively
void rearrange(vector<int> &arr)
{
	vector<int> pos;
	vector<int> neg;

	for(int i=0; i<arr.size(); i++){
		if(arr[i]>0) pos.push_back(arr[i]);
		else neg.push_back(arr[i]);
	}

	if(pos.size()<neg.size()){
		for(int i=0; i<pos.size(); i++){
			arr[2*i]=pos[i];
			arr[2*i+1]=neg[i];
		}

		int index= pos.size()*2;
		for(int i=pos.size(); i<neg.size(); i++){
			arr[index]=neg[i];
			index++;
		}
	} else {
		for(int i=0; i<neg.size(); i++){
			arr[2*i]=pos[i];
			arr[2*i+1]=neg[i];
		}

		int index= neg.size()*2;
		for(int i=neg.size(); i<pos.size(); i++){
			arr[index]=pos[i];
			index++;
		}
	}

}

