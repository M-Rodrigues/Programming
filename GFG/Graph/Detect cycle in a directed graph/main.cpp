// link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// dfs + 3 state traversal

{
#include<bits/stdc++.h>
using namespace std;
bool isCyclic(vector<int> g[], int V);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        vector<int> g[101];
        int V, E;
        cin>>V>>E;
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
        }
        cout << isCyclic(g, V);
        cout << endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// The array of vectors g[] stores adjacency list 
// representation of a directed graph. Here g[u] 
// is a vector containing all adjacent of vertex u.
/*You are required to complete this method*/

bool dfs(int v, vector<int> g[], vector<int> &vis);

bool isCyclic(vector<int> g[], int V)
{
    vector<int> vis(V, 0);
    bool ans = false;
    
    for (int v = 0; v < V; v++)
        if (vis[v] == 0)
            ans |= dfs(v, g, vis);
                
    return ans;
}

bool dfs(int v, vector<int> g[], vector<int> &vis) {
    if (vis[v] == 2) return false;
    if (vis[v] == 1) return true;
    
    vis[v] = 1;
    bool ans = false;
    
    for (int u : g[v])
        ans |= dfs(u, g, vis);
    vis[v] = 2;
    
    return ans;
}
