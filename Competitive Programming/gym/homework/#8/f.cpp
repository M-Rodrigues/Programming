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

int op, i, j, p, n, q;
ll a[N], stmx[4*N], stmn[4*N];

void build_max(int n, int l, int r) {
	if (l == r) stmx[n] = a[l];
	else {
		int mid = (l+r)/2;

		build_max(2*n, l, mid);
		build_max(2*n+1, mid+1, r);

		stmx[n] = max(stmx[2*n],stmx[2*n+1]);
	}
}

void update_max(int n, int i, int l, int r, int val) {
	if (i < l or i > r) return;
	if (l == r) stmx[n] = a[l];
	else {
		int mid = (l+r)/2;
		update_max(2*n, i, l, mid, val);
		update_max(2*n+1, i, mid+1, r, val);
		
		stmx[n] = max(stmx[2*n],stmx[2*n+1]);
	}
}

void build_min(int n, int l, int r) {
	if (l == r) stmn[n] = a[l];
	else {
		int mid = (l+r)/2;

		build_min(2*n, l, mid);
		build_min(2*n+1, mid+1, r);

		stmn[n] = min(stmn[2*n],stmn[2*n+1]);
	}
}

void update_min(int n, int i, int l, int r, int val) {
	if (i < l or i > r) return;
	if (l == r) stmn[n] = a[l];
	else {
		int mid = (l+r)/2;
		update_min(2*n, i, l, mid, val);
		update_min(2*n+1, i, mid+1, r, val);
		
		stmn[n] = min(stmn[2*n],stmn[2*n+1]);
	}
}

ll query_max(int n, int i, int j, int l, int r) {
	if (l >= i and r <= j) return stmx[n];
	if (r < i or l > j) return 0;
	
	ll sum = 0;
	int mid = (l+r)/2;

	return max(query_max(2*n, i, j, l, mid), query_max(2*n+1, i, j, mid+1, r));
}

ll query_min(int n, int i, int j, int l, int r) {
	if (l >= i and r <= j) return stmn[n];
	if (r < i or l > j) return INF;
	
	ll sum = 0;
	int mid = (l+r)/2;

	return min(query_min(2*n, i, j, l, mid), query_min(2*n+1, i, j, mid+1, r));
}

void printArrays() {
	for (int i = 1; i <= n; i++) printf("%lld ",a[i]); printf("\n");
	for (int i = 1; i <= 4*n; i++) printf("%lld ",stmn[i]); printf("\n");
	for (int i = 1; i <= 4*n; i++) printf("%lld ",stmx[i]); printf("\n\n");
}

int main() {
	while (scanf("%d",&n) != EOF) {
		cl(a, 0);
		cl(stmx, 0);
		cl(stmn, 0);
		for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);

		build_min(1,1,n);
		build_max(1,1,n);


		scanf("%d",&q);
		while (q--) {
			scanf("%d",&op);
			if (op == 1) {
				scanf("%d%d",&i,&p);

				a[i] = p;
				update_min(1,i,1,n,p);
				update_max(1,i,1,n,p);
			} else {
				scanf("%d%d",&i,&j);

				ll mx = query_max(1,i,j,1,n);
				ll mn = query_min(1,i,j,1,n);

				printf("%lld\n",mx-mn);
			}
		}
	}

	return 0;
}
