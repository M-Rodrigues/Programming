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

ll a[N], st[4*N];
int n, q, i, x, l, r;
char op;

void build(int n, int l, int r) {
	if (l == r) st[n] = a[l];
	else  {
		int  mid = (l+r)/2;
		build(2*n, l, mid);
		build(2*n+1, mid+1, r);

		st[n] = st[2*n] + st[2*n+1];
	}
}

void update(int n, int i, int l, int r, int val) {
	if (i < l or i > r) return;
	if (l == r) st[n] += val;
	else {
		int mid = (l+r)/2;
		update(2*n, i, l, mid, val);
		update(2*n+1, i, mid+1, r, val);
		
		st[n] = st[2*n] + st[2*n+1];
	}
}

ll query(int n, int i, int j, int l, int r) {
	if (l >= i and r <= j) return st[n];
	if (r < i or l > j) return 0;
	
	ll sum = 0;
	int mid = (l+r)/2;

	sum += query(2*n, i, j, l, mid);
	sum += query(2*n+1, i, j, mid+1, r);

	return sum;
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%lld",&a[i]);

	build(1,1,n);

	scanf("%d",&q);
	while (q--) {
		cin >> op >> l >> r;
		if (op == 'q') {
			//query -> soma entre os indices l, r inclusive
			printf("%lld\n",query(1,l,r,1,n));
		} else {
			i = l; x = r;
			// update x na posição i
			update(1,i,1,n,x);
		}
	}
	return 0;
}
