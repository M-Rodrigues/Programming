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

int main() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		int mm = max({a, b, c});
		int mn = min({a, b, c});

		if (a != mm and a != mn){
			cout << "Case " << i << ": " << a << endl;
			continue;
		}
		if (b != mm and b != mn){
			cout << "Case " << i << ": " << b << endl;
			continue;
		}
		if (c != mm and c != mn){
			cout << "Case " << i << ": " << c << endl;
			continue;
		}
	}

	return 0;
}
