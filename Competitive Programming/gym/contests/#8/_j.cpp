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

struct BIT {
	ll bit[N] = {};

	ll sum(int x) {
		ll ans = 0;
		while (x) ans += bit[x], x -= x&(-x);
		return ans;
	}

	void upd(int x, ll v) {
		while (x < N) bit[x] += v, x += x&(-x);
	}
};

struct BITRange {
	BIT a, b;

	ll sum(int x) {
		return a.sum(x)*x+b.sum(x);
	}

	void upd(int l, int r, ll v) {
		a.upd(l,v), a.upd(r+1,-v);
		b.upd(l,-v*(l-1)), b.upd(r+1,v*r);
	}
};

int main() {
	int t; scanf("%d",&t);

	while (t--) {
		BITRange bit;
		int n, c; scanf("%d%d",&n,&c);

		while (c--) {
			int p, q, op; scanf("%d%d%d",&op,&p,&q);
			if (op) {
				printf("%lld\n",bit.sum(q) - bit.sum(p-1));
			} else {
				int v; scanf("%d",&v);
				bit.upd(p,q,v);
			}
		}
	}
	return 0;
}
