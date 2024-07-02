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


// Optimal Approach- Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
// Space Complexity: O(1).
void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }