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