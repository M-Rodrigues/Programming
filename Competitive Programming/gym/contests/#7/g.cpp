#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+5;

ll n, m, pai[N], size[N], w[N], ans;
priority_queue<pair<ll, pair<int, int>>> edges;

int find(int x) {
	return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void unite(int a, int b, ll  v) {
	a = find(a);
	b = find(b);
	
	if(a == b) return;

	ans += size[a]*size[b]*v;
	if (size[a] > size[b]) swap(a,b);
	size[b] += size[a];
	pai[a] = b;
}

int main() {
	scanf("%lld%lld",&n,&m);
	
	for (int i = 1; i <= n; i++) scanf("%lld",&w[i]), pai[i]=i, size[i]=1;
	
	while (m--) {
		int a, b, mn;
		scanf("%d%d",&a,&b);
		mn = min(w[a],w[b]);
		edges.push(make_pair(mn, make_pair(a,b)));
		edges.push(make_pair(mn, make_pair(b,a)));
	}

	while (!edges.empty()) {
		pair<ll, pair<int,int>> e = edges.top(); edges.pop();
		unite(e.second.first, e.second.second, e.first);
	}
	
	ll t = n*(n-1)/2;
	printf("%.8lf\n",double(ans)/double(t));	

	return 0;
}
