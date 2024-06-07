#include <bits/stdc++.h>
using namespace std;

// Brute force-Time Complexity: O(N*N) to linearly iterate and put it into some other matrix.
// Space Complexity: O(N*N) to copy it into some other matrix.
vector<vector<int>>rotateMatrix(vector<vector<int>> &mat){
	int n=mat.size();
	vector<vector<int>> ans(n, vector<int>(n,0));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ans[j][n-i-1]= mat[i][j];
		}
	}
	return ans;
}

// Optimal Approach- t.c-O(n2) and s.c- O(1);

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

	// int row[n]={0}; matrix[..][0]
	// int col[m]={0}; matrix[0][..]
	int col0=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==0){
				// To mark row
				matrix[i][0]=0;
				// To mark col
				if(j!=0){
					matrix[0][j]=0;
				} else {
					col0=0;
				}
				
			}
		}
	}

	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(matrix[i][j]!=0){
				if(matrix[i][0]==0 || matrix[0][j]==0){
					matrix[i][j]=0;
				}
			}
		}
	}
	if(matrix[0][0]==0){
		for(int j=0; j<m; j++){
			matrix[0][j]=0;
		}
	}
	if(col0==0){
		for(int i=0; i<n; i++){
			matrix[i][0]=0;
		}
	}
	return matrix;
}