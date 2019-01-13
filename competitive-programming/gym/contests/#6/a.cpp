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
const int N = 2e4+5;

int T, n, k;
int a[N], st[4*N];

void build(int n, int l, int r) {
	if (l == r) st[n] = a[l];
	else {
		int mid = (l+r)/2;
		build(2*n, l, mid);
		build(2*n+1, mid+1, r);

		st[n] = st[2*n] & st[2*n+1];
	}
}

int query(int n, int l, int r, int i, int j) {
	if (r < i or l > j) return -1;
	if (l >= i and r <= j) return st[n];

	int mid = (l+r)/2;

	int ans = query(2*n,l,mid,i,j);
	ans &= query(2*n+1,mid+1,r,i,j);
	return ans;
}

int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&k);
		for (int i = 0; i < n; i++) scanf("%d",&a[i]);
		build(1,0,n-1);

		for (int i = 0; i < n; i++) {
			int ans;
			if (k >= n) ans = st[1];
			else if (i-k < 0)
				ans = query(1,0,n-1,0,i+k) & query(1,0,n-1,n+i-k,n-1);
			else if (i+k >= n)
				ans = query(1,0,n-1,i-k,n-1) & query(1,0,n-1,0,(i+k)-n);
			else ans = query(1,0,n-1,i-k,i+k);

			cout << ans << " \n"[i == n - 1];
		}
		// printf("\n");
	}
	return 0;
}
