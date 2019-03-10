#include<bits/stdc++.h>
using namespace std;

bool insideBoard(int i, int j, int n, int m) {
	return !(i < 0 or i >= n or j < 0 or j >= m);
}

void dfs(int i, int j, int oldColor, int newColor, vector<vector<int>> &m, int* dx, int* dy) {
	int nn = (int)m.size(); if (nn == 0) return;
	int mm = (int)m[0].size();
	if (!insideBoard(i,j,nn,mm)) return;

	if (m[i][j] != oldColor) return;

	m[i][j] = newColor;
	for (int k = 0; k < 4; k++)
		dfs(i+dx[k],j+dy[k],oldColor,newColor,m,dx,dy);
}

void paintFill(vector<vector<int>> &m, int ii, int jj, int newColor) {
	int nn = (int)m.size(); if (nn == 0) return;
	int mm = (int)m[0].size();

	if (!insideBoard(ii,jj,nn,mm)) return;

	int oldColor = m[ii][jj];
	int dx[8] = {0,1,0,-1};
	int dy[8] = {1,0,-1,0};
	dfs(ii,jj,oldColor,newColor,m,dx,dy);
}






int main() {
	int n, m; cin >> n >> m;
	
	vector<vector<int>> board;
	for (int i = 0; i < n; i++) {
		vector<int> line;
		for (int j = 0; j < m; j++) {
			int c; cin >> c;
			line.push_back(c);
		}
		board.push_back(line);
	}

	paintFill(board, 1, 1, 3);

	for (auto l : board) {
		for (int x : l)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}
