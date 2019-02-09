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

int sz, p;
int steps = 1, m = 0;
pii pp = {1,1};

void next() {
	if (m == 0) pp.nd++; 
	if (m == 1) pp.st--; 
	if (m == 2) pp.nd--;
	if (m == 3) pp.st++;
}

int main() {
	while (cin >> sz >> p, sz+p) {
		pp = {1,1}; steps = 1; m = 0;
		
		while (p>1) {
			for (int i = 0; i < 2; i++) {
				for (int k = 0; k < steps; k++) {
					next();
					if (--p==1) break;
				}
				m = (m+1)%4;
				if (p==1) break;
			}
			steps++;
			if (p==1) break;
		}
		
		pp.st += sz/2;
		pp.nd += sz/2;

		printf("Line: %d, column: %d\n",pp.nd, pp.st);
	}
	return 0;
}
