#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<int> *adj;

    Graph(int V);
    ~Graph();
    void addEdge(int x, int y);
    bool isRoute(int x, int y);
};

Graph::Graph(int V) {
    this->V = V;
    this->adj = new vector<int>[V];
}
Graph::~Graph() {
    for (int i = 0; i < V; i++)
        adj[i].clear();
}

void Graph::addEdge(int x, int y) {
    adj[x].push_back(y);
}

bool Graph::isRoute(int x, int y) {
    vector<bool> visited(V,false);
    queue<int> q;

    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = true;

        if (u == y) return true;

        for (int v : adj[u]) if (!visited[v])
            q.push(v);
    }
    return false;    
}

int main() {

    Graph g(6);	
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << g.isRoute(5,4) << endl;
    cout << g.isRoute(5,1) << endl;

    return 0;
}