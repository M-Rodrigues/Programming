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
	int k;
	cin >> k;
	while(k) {
		pii c;
		cin >> c.st >> c.nd;
		while (k--) {
			pii p;
			cin >> p.st >> p.nd;

			int x = p.st - c.st;
			int y = p.nd - c.nd;

			if (x == 0 || y == 0) {
				cout << "divisa" << endl;
				continue;
			}

			char c1 = y > 0 ? 'N' : 'S';
			char c2 = x > 0 ? 'E' : 'O';

			cout << c1 << c2 << endl;		
		}

		cin >> k;
	}

	return 0;
}
