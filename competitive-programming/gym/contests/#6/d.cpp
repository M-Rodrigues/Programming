#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 2e5+5;
typedef long long ll;

int n, m;
vector<ll> adj[N], adjw[N];
ll dist[N], vis[N];
priority_queue<pair<ll,ll>> pq;

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; i++) {
		ll u,v;
		ll w;
		scanf("%lld%lld%lld",&u,&v,&w);
		adj[u].pb(v);
		adj[v].pb(u);

		adjw[u].pb(2*w);
		adjw[v].pb(2*w);
	}

	for (int i = 1; i <= n; i++) {
		ll c;
		scanf("%lld",&c);
		adj[i].pb(0);
		adj[0].pb(i);

		adjw[i].pb(c);
		adjw[0].pb(c);
	}

	pq.push(make_pair(0,0));

	while (!pq.empty()) {
		ll u = pq.top().second;
		ll c = -pq.top().first;
		pq.pop();

		if (vis[u]) continue;

		vis[u] = 1;
		dist[u] = c;

		for (int i = 0; i < adj[u].size(); i++) {
			ll v = adj[u][i];
			ll w = adjw[u][i];

			pq.push(make_pair(-(c+w),v));
		}
	}

	for (int i = 1; i <= n; i++) printf("%lld ",dist[i]); printf("\n");

	return 0;
}
