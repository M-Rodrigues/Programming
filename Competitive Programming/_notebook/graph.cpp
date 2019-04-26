#include<bits/stdc++.h>
typedef long long ll;

/*          DFS           */
int vis[N];
vi adj[N];

void dfs(int x) {
    vis[x] = 1;
    for (int v : adj[x]) if(!vis[v])
        dfs(v);
}
    
/*          BFS           */
int vis[N], dist[N];
vi adj[N];
queue<int> q;

q.push(1);
vis[1] = 1;
dist[1] = 0;

while (!q.empty()) {
    int u = q.front(); q.pop();

    for (int v : adj[u]) if (!vis[v]) {
        dist[v] = dist[u] + 1; q.push(v);
    }
}

/*       Kahn - Topological Sort      */
int vis[N], inc[N];
vi adj[N];
queue<int> q;

for (int i = 1; i < n; i++) if (inc[i] == 0) q.push(i);

while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u])
        if (inc[v] > 0 and --inc[v] == 0)
            q.push(v)
}
        

// Disjoint Set Union (Union Find) - O(alfa(n)) ~= O(1)
int pai[N], sz[N];

int find(int x) {
    return (pai[x] == x) ? x : pai[x] = find(pai[x]); // Compressão de caminho
}

void unite(int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a,b); // Union by size
    pai[b] = a;
    sz[a] += sz[b];
}

// Menor Caminho - Dijkstra - O((E+V)log(E))
vi adj[N], adjw[N];
int dist[N];

cl(dist, 63);
priority_queue<pii> pq;
pq.push(mp(0,0));

while(!pq.empty()) {
    int u = pq.top().nd;
    int d = -pq.top().st;

    pq.pop();   

    if (d > dist[u]) continue;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        int w = adjw[u][i];

        if (dist[u] + w < dist[v])
            dist[v] = dist[u] + w, pq.push(mp(-dist[v],v));
    }
}


// Menor Caminho - Bellman-Ford - O(VE)
int dist[N];

cl(dist, 63);
dist[0] = 0;
for (int i = 0; i < n-1; i++)
    for (int u = 0; u < n; u++)
        for (int j = 0; j < adj[u].size(); j++)
            dist[u] = min(dist[u], dist[adj[u][j]] + adjw[u][j]);

// Floyd Warshall - Menor distância entre todos os possíveis pares
int adj[N][N]; // cl(adj, 63);

for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);

// Prim (MST)



// Kruskal (MST)
vector<piii> edges;

sort(edges.begin(), edges.end());
ll = mn_w = 0;
for (piii e : edges) {
    int a = e.nd.st;
    int b = e.nd.nd;
    int w = e.st;

    if (find(a) != find(b)) {
        unite(e.nd.st,e.nd.st);
        mn_w += w;
    }
}