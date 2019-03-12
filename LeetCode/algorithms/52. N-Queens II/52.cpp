class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> m;
        for (int i = 0; i < n; i++) {
            vector<int> l;
            for (int j = 0; j < n; j++)
                l.push_back(0);
            m.push_back(l);
        }
        
        ans = 0;
		bt(0,0,m);
        return ans;
    }
private:
    int ans = 0;
    
	bool emptyRow(int i, vector<vector<int>> &m) {
		for (int x : m[i]) if (x != 0) return false;
		return true;
	}

    bool isValidPosition(int ii, int jj, vector<vector<int>> &m) {
        int n = (int)m.size();
        for (int i = 0; i < n; i++) if (i != ii and m[i][jj] == 1) return false;
        for (int j = 0; j < n; j++) if (j != jj and m[ii][j] == 1) return false;
        
        for (int k = 1; ii+k < n and jj+k < n; k++) if (m[ii+k][jj+k] == 1) return false;
        for (int k = 1; ii+k < n and jj-k >= 0; k++) if (m[ii+k][jj-k] == 1) return false;
        for (int k = 1; ii-k >= 0 and jj+k < n; k++) if (m[ii-k][jj+k] == 1) return false;
        for (int k = 1; ii-k >= 0 and jj-k >= 0; k++) if (m[ii-k][jj-k] == 1) return false;
        
        return true;
    }
    
    void bt(int i, int j, vector<vector<int>> &m) {
        /* extrapolou o limite interior -> configuração válida */
        if (i == m.size()) { ans++; return; }
        
        /* extrapolou o limite lateral */
        if (j == m.size()) { 
			if (!emptyRow(i,m)) bt(i+1,0,m); 
			return; 
		}
        
        if (!isValidPosition(i,j,m)) { bt(i,j+1,m); return;}
        
        m[i][j] = 1;
        bt(i+1,0,m);
        m[i][j] = 0;
		bt(i,j+1,m);
    }
};