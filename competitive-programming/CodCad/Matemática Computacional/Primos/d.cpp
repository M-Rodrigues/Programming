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
	int a, b, c, d, n, k1 = 1, k2 = 1;
	scanf("%d%d%d%d",&a,&b,&c,&d);

	for (int k1 = 1;k1*k2 <= c/a;k1++) {
		bool ok = false;
		for (int k2 = 1; k1*k2 <= c/a; k2++) {
			n = k1*a;
			if (n%b != 0 && d%n != 0) ok = true;

			if(ok) break;
		}
		if(ok) break;
	}

	if (k1*k2 > n) n = -1;
	
	printf("%d\n",n);

	return 0;
}
