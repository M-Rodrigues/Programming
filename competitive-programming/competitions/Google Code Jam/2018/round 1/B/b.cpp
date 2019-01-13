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
const int N = 1e6+5;

int s, T, dist[N];
map<int, pair<int,int>> sgns;
map<int, int> vis, size, pai;

int find(int x) {
	return (pai[x] == x) ? x : pai[x] = find(pai[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;

	if (size[a] > size[b]) swap(a,b);
	pai[a] = b;
	size[b] += size[a];
}
int main() {
	scanf("%d",&T);
	for (int t = 1; t <= T; t++) {
		sgns.clear();
		vis.clear();
		cl(dist, 0);

		scanf("%d",&s);
		for (int i = 0; i < s; i++) {
			int d, a, b;
			scanf("%d%d%d",&d,&a,&b);
			sgns[d] = mp(a,b);
			dist[i] = d;
			vis[d] = 0;
		}

		for (int i = 0; i < N; i++) size[N] = 1, pai[i] = i;

		for (int i = 0; i < s; i++) {
			int di = dist[i];

			if (vis[di] == 0) {
				vis[di] = 1;

				pii P = sgns[di];
				int ai = P.st;
				int bi = P.nd;

				// ver se di+ai existe
				if (sgns.count(di+ai) != 0) {
					// adicionar ao conjunto do di
					int l = di+ai;
					if (find(di) != find(l))
						unite(di,l);
				}

				// ver se di-bi existe
				if (sgns.count(di-bi) != 0) {
					// adicionar ao conjunto do di
					int r = di-bi;
					if (find(di) != find(r))
						unite(di,r);
				}
			}
		}

		int ls = 0;
		for (int i = 0; i < s; i++) {
			int di = dist[i];
			
			if (size[di] > ls) {
				ls = size[di];
			} 
		}


		printf("Case #%d: %d\n",t, ls);
	}
	return 0;
}
