class Solution {
    class Graph {
        vector<vector<int>> adj;
        vector<int> inc, vis, order;
        int N;
    public:
        Graph(int n): N(n) {
            inc.assign(N, 0); vis.assign(N, 0);
            for (int i = 0; i < N; i++) {
                vector<int> aux;
                adj.push_back(aux);
            }
        }
        
        void setEdges(vector<pair<int, int>>& edges) {
            for (pair<int, int> e : edges) {
                int a = e.first, b = e.second;
                inc[a]++; adj[b].push_back(a);
            }
        }
    
        vector<int> canFinish() {
            for (int i = 0; i < N; i++)
                if (inc[i] == 0 and vis[i] == 0) {
                    order.push_back(i);
                    dfs(i);
                }
            
            for (int i = 0; i < N; i++)
                if (inc[i] != 0) return {};
            
            return order;
        }
    private:
        void dfs(int v) {
            if (vis[v]) return;
            vis[v] = 1;
            
            for (int i = 0; i < adj[v].size(); i++) {
                int u = adj[v][i];
                inc[u]--;
                
                if (inc[u] == 0) {
                    order.push_back(u);
                    dfs(u);
                }
            }
        }        
    };
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph g(numCourses);
        g.setEdges(prerequisites);
        return g.canFinish();
    }
};