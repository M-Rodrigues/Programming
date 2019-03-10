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

vector<pii> op;
vi d;
ll arr[N], pf_arr[N], pf_op[N];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 0; i < m; i++) {
		int l, r, dd;
		cin >> l >> r >> dd;

		op.pb({l,r});
		d.pb(dd);
	}
	
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;

		pf_op[y+1]--;
		pf_op[x]++;
	}


	for (int i = 1; i < N; i++) pf_op[i] += pf_op[i-1];
	
	for (int i = 0; i < m; i++) {
		int dd = d[i];
		pii p = op[i];

		ll tt = pf_op[i+1];


		pf_arr[p.st] += dd*tt;
		pf_arr[p.nd+1] -= dd*tt;
	}

	for (int i = 1; i < N; i++) pf_arr[i] += pf_arr[i-1];

	for (int i = 1; i <= n; i++) cout << arr[i] + pf_arr[i] << " ";
	cout << endl;

	return 0;
}
