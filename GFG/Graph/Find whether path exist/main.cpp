#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    Graph(int n): N(n) {
        adj.assign(n*n, vector<int>());
        tab.assign(n, vector<int>(n, 0));
    }
    
    void addEdge(int i, int j, int c) {
        tab[i][j] = c;
    }
    
    int has_path() {
        build_graph();
        
        vector<bool> vis(N*N, false);
        dfs(src, vis);
        
        return vis[dest] ? 1 : 0;
    }
    
private:
    int src, dest, N;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    vector<vector<int>> adj, tab;
    
    void build_graph() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int c = tab[i][j];
                if (c == 0) continue;
        
                int pos = i*N+j;
                if (c == 1) src = pos;
                if (c == 2) dest = pos;
                
                for (int k = 0; k < 4; k++) {
                    int ii = i+dx[k], jj = j+dy[k];
                    if (inside(ii,jj) and tab[ii][jj] != 0)
                        adj[i*N+j].push_back(ii*N+jj);
                }
                
            }
        }
    }
    
    bool inside(int i, int j) {
        return (i >= 0 and i < N) and (j >= 0 and j < N);
    }
    
    void dfs(int x, vector<bool> &vis) {
        if (vis[x]) return;
        vis[x] = true;
        
        for (int u : adj[x])
            dfs(u, vis);
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        Graph g(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cell; cin >> cell;
                g.addEdge(i,j,cell);
            }
        }
        
        cout << g.has_path() << endl;
    }
	return 0;
}