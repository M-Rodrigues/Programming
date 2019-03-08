#include <bits/stdc++.h>
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

int a[N], st[N], n, q, l, r;

int amt(int x, int l, int r) {
	return upper_bound(a+l, a+r+1, x) - lower_bound(a+l, a+r+1, x);
}

void build(int n, int l, int r) {
	if (l == r) st[n] = 1;
	else {
		int mid = (l+r)/2;

		build(2*n, l, mid);
		build(2*n+1, mid+1, r);

		st[n] = max({amt(a[mid], l, r), st[2*n], st[2*n+1]});
	}
}

int query(int n, int l, int r, int i, int j) {
	if(j < l or i > r) return 0;
  	if(i <= l and j >= r) return st[n];

	int mid = (l+r)/2;	
	
	int ans = query(2*n, l, mid, i, j);
	ans = max(ans, query(2*n + 1, mid + 1, r, i, j));
	ans = max(ans, amt(a[mid], i, j));
	return ans;
}

int main() {
	while (scanf("%d",&n) and n) {
		scanf("%d",&q);
		
		for (int i = 1; i <= n; i++) scanf("%d",&a[i]);

		build(1,1,n);

		while (q--) {
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1, 1, n, l, r));
		}
	}

	return 0;
}
