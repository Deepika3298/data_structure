#include <bits/stdc++.h>
using namespace std;

// Brute force Approach- T.C.-O(n3) & S.C- O(1)
void markRow(vector<vector<int>> &matrix, int n, int m, int i){
	for(int j=0; j<m; j++){
		if(matrix[i][j]!=0){
			matrix[i][j]=-1;
		}
	}
}

void markColumn(vector<vector<int>> &matrix, int n, int m, int j){
	for(int i=0; i<n; i++){
		if(matrix[i][j]!=0){
			matrix[i][j]=-1;
		}
	}
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==0){
				markRow(matrix, n, m, i);
				markColumn(matrix, n, m ,j);
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==-1){
				matrix[i][j]=0;
			}
		}
	}
	return matrix;
}

// Better Approach- T.c- O(2*n*m) and S.C.- O(n)+ O(m)
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	int row[n]={0};
	int col[m]={0};
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==0){
				row[i]=1;
				col[j]=1;
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(row[i] || col[j]){
				matrix[i][j]=0;
			}
		}
	}
	return matrix;
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