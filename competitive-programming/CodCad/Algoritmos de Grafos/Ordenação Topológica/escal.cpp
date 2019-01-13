#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int inc[N], n, m, a, b;
vi adj[N], ts;
priority_queue<int> pq;

int main() {
	scanf("%d%d",&n,&m);

	while (m--) {
		scanf("%d%d",&a,&b);
		adj[a].pb(b);
		inc[b]++;
	}
	for (int i = 0; i < n; i++) if(!inc[i]) pq.push(-i);

	while (!pq.empty()) {
		int u = -pq.top(); pq.pop();
		ts.pb(u);

		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			inc[v]--;

			if (inc[v] == 0) pq.push(-v);
		}
	}

	
	if (ts.size() == n)
		for (int v : ts) printf("%d\n",v);
	else 
		printf("*\n");
	return 0;
}
