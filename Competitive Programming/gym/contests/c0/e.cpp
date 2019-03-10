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

int mm, a, n;
ll sum;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += a;
		mm = max(mm, a);
	}
	

	int q = sum/(n-1), r = sum%(n-1);

	// db(sum _ mm _ n);
	// db(q _ r);

	if (r != 0) q++;

	if (mm <= q) {
		printf ("%d\n",q);
	} else {
		printf("%d\n",mm);
	}

	
	return 0;
}
