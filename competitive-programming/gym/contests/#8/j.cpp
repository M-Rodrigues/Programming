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

int t, n, c, p, q, op;
ll st[4*N], lz[4*N];

void push(int p, int l, int r) {
	if (lz[p]) {
		st[p] += lz[p]*(r-l+1);

		if (l != r) 
			lz[2*p] += lz[p], 
			lz[2*p+1] += lz[p];

		lz[p] = 0;
	}
}

ll query(int p, int l, int r, int i, int j) {
	push(p, l, r);

	if (r < i or l > j) return 0;
	if (l >= i and r <= j) return st[p];
	return query(2*p, l, (l+r)/2, i, j) + query(2*p+1, (l+r)/2+1, r, i, j);
}

void update(int p, int l, int r, int i, int j, int v) {
	push(p, l, r);

	if (r < i or l > j) return;
	if (l >= i and r <= j) { 
		lz[p] = v; 
		push(p, l, r); 
		return; 
	}
		update(2*p, l, (l+r)/2, i, j, v);
		update(2*p+1, (l+r)/2+1, r, i, j, v);
		st[p] = st[2*p] + st[2*p+1];
}

void pa() { 
	for (int i=1;i<=n;i++) printf("%lld ",query(1,1,n,i,i)); printf("\n\n");
}
int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&n,&c);
		cl(st, 0);
		cl(lz, 0);

		while (c--) {
			scanf("%d%d%d",&op,&p,&q);
			if (op == 0) {
				int v; scanf("%d",&v);
				update(1,1,n,p,q,v);
			} else {
				printf("%lld\n",query(1,1,n,p,q));
			}
		}
	}
	return 0;
}
