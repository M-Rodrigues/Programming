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

ll T, D, t = 0;
string p;

ll damage(string &s) {
	ll power = 1, total = 0;
	for (char c : s)
		if (c == 'S') total += power;
		else power *= 2;
	return total;
}

string swapLastS(string &s) {
	ll pos = 0;
	for (ll i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'C' and s[i+1] == 'S') pos = i; 
	}
	if (pos != 0 or (pos == 0 and s[pos] == 'C' and s[pos+1] == 'S'))swap(s[pos],s[pos+1]);
	return s;
}

int main() {
	cin >> T;
	while (T--) {
		t++;
		cin >> D >> p;

		ll total_S = 0;
		for (char c : p) if (c == 'S') total_S++;
		
		if (total_S > D) {
			printf("Case #%lld: IMPOSSIBLE\n",t);
		} else {			
			ll moves = 0;
			
			while (damage(p) > D)
				p = swapLastS(p), moves++;
			
			printf("Case #%lld: %lld\n",t,moves);
		}		
	}
	return 0;
}
