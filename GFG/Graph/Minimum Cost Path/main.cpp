// link: https://practice.geeksforgeeks.org/problems/minimum-cost-path/0

// Dijkstra

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    Graph(int N): n(N) {
        adjw.assign(n*n, 0);
        adj.assign(n*n, vector<int>());
    }
    
    void addEdge(int i, int j, int w) {
        for (int k = 0; k < 4; k++) {
            adjw[node(i,j)] = w;
            if (inside(i+dx[k], j+dy[k])) {
                adj[node(i,j)].push_back(node(i+dx[k],j+dy[k]));
            }
        }
    }
    
    int minimum_cost() {
        vector<int> dist(n*n, INT_MAX);
        vector<bool> vis(n*n, false);
        priority_queue<pair<int,int>> pq;
        
        
        dist[0] = 0;
        pq.push({0,0});
        
        while (!pq.empty()) {
            int v = pq.top().second;
            pq.pop();
            
            if (vis[v]) continue;
            vis[v] = true;
            
            for (int i = 0; i < adj[v].size(); i++) {
                int u = adj[v][i];
                int w = adjw[v];
                
                if (dist[v] + w < dist[u]) {
                    dist[u] = dist[v] + w;
                    pq.push({-dist[u], u});
                }
            }
        }
        return dist[n*n-1] + adjw[n*n-1];
    }
    
private:
    int n;
    vector<int> adjw;
    vector<vector<int>> adj;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    
    int node(int i, int j) { return i*n+j; }
    
    bool inside(int i, int j) {
        return (i >= 0 and i < n) and (j >= 0 and j < n);
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        Graph *g = new Graph(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int w; cin >> w;
                g->addEdge(i,j,w);
            }
        }
        
        cout << g->minimum_cost() << endl;
        delete g;
    }
	return 0;
}