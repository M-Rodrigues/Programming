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

ll n, k, d, X[N], Y[N];

ll dx(ll i) {
	if (~X[i]) return X[i];
	if (i > n) return X[i] = 0;
	if (i == n) return X[i] = 1;

	ll res = 0;

	for (ll j = i+1; j <= i+k; j++) res = (res + dx(j))%MOD;

	return X[i] = res;
}

ll dy(ll i) {
	if (~Y[i]) return Y[i];
	if (i >= n) return Y[i] = 0;

	ll res = 0;

	for (ll j = i+1; j <= i+d-1; j++) res = (res + dy(j))%MOD;
	
	for (ll j = i+d; j <= i+k; j++) res = (res + dx(j))%MOD;
	
	return Y[i] = res;
}


int main() {
	scanf("%lld%lld%lld",&n,&k,&d);
	cl(X, -1);
	cl(Y, -1);

	printf("%lld\n",dy(0));
	return 0;
}
