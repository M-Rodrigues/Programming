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

int n, b, h, w, ans;

int main() {
	while (cin >> n >> b >> h >> w) {
		ans = -1;
		while(h--) {
			int p, qtd;
			cin >> p;
			for (int i = 0; i < w; i++) {
				cin >> qtd;

				if (qtd >= n) {
					int cur = n*p;

					if ((ans == -1 and cur <= b) or cur < ans) ans = cur;
				}
			}
		}
		if (ans == -1) 
			cout << "stay home" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
