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

int n, op, x, q, l, r, val;
ll bit[N];

// void printArray() { 
// 	for (int i = 1; i <= n; i++) printf("%lld ",arr[i]); printf("\n");
// 	for (int i = 1; i <= n; i++) printf("%lld ",bit[i]); printf("\n\n"); 
// }

void add(int x, int val) {
	for (x+=2; x<N; x+=x&-x) bit[x] += val;
}

ll query(int p) {
  ll r = 0;
  for (p+=2; p>0; p-=p&-p) r += bit[p];
  return r;
}

int main() {
	scanf("%d",&n);
	for (int i = n; i > 0; i--) {
		scanf("%d",&val);
		// arr[i] = val;
		add(i, val);
	}
	// printArray();

	scanf("%d",&q);
	while (q--) {
		scanf("%d",&op);
		if (op == 1) {
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(n-l+1) - query(n-r));
		} else {
			scanf("%d",&val);
			add(n+1, val);
			n++;
		}
	}
	return 0;
}
