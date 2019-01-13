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
const int N = 1e3+5;

int n;
ld p, w[N], h[N], memo[N];
pair<ld, ld> cookies[N];

ld solve(int i, ld P) {
	if (i == n) return 0;
	if (P + EPS > 0 or P - EPS > 0) return 0;

	if (memo[i] != -1) return memo[i];

	ld n_cortar = 2*(w[i]+h[i]) + solve(i+1,P - 2*(w[i]+h[i]));
	ld cortar_vert = 2*(w[i]/2 + h[i]) + solve(i+1, P - 2*(w[i]/2 + h[i]));
	ld cortar_hor = 2*(w[i] + h[i]/2) + solve(i+1, P - 2*(w[i] + h[i]/2));

	ld dif1 = abs(p - n_cortar);
	ld dif2 = abs(p - cortar_vert);
	ld dif3 = abs(p - cortar_hor);

	vector< pair<ld,ld> > v;
	v.pb(mp(dif1, n_cortar));
	v.pb(mp(dif2, cortar_vert));
	v.pb(mp(dif3, cortar_hor));

	sort(v.begin(),v.end());

	if (v[0].nd < p + EPS)
		return memo[i] = v[0].nd;
	else if (v[1].nd < p + EPS)
		return memo[i] = v[1].nd;
	else
		return memo[i] = v[2].nd;
} 

int main() {
	int T;
	scanf("%d",&T);
	for (int t = 1; t <= T; t++) {
		cl(cookies, 0);
		cl(memo, -1);

		cin >> n >> p;
		
		for (int i = 0; i < n; i++)
			cin >> w[i] >> h[i];

		
		cout << setprecision(7) << "Case #" << t << " : " << solve(0,p) << endl;
	}
	return 0;
}
