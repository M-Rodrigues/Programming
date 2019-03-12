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

void build(int n, vector<ll> &ln) {
	queue<pair<ll,int>> q; q.push({0,0});
	
	while (!q.empty()) {
		ll x = q.front().first;
		int l = q.front().second;
		q.pop();

		if (l < n) {
			ln.push_back(10*x+4);
			ln.push_back(10*x+7);

			q.push({10*x+4, l+1}); 
			q.push({10*x+7, l+1});
		}
	}
}

int main() {
	vector<ll> ln;
	build(9,ln);

	int id = (lower_bound(ln.begin(), ln.end(), 444444444) - ln.begin());
	ln.resize(id);

	int l, r; cin >> l >> r;
	id = (lower_bound(ln.begin(), ln.end(), l) - ln.begin());

	ll ans = 0;
	for (int i = l; i <= r; i++) {
		if (ln[id] < i) id++;
		
		ans += ln[id];
	}

	cout << ans << endl;
	return 0;
}
