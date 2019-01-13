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
const int N = 1e6+5;

int a[N], t, n, ansi, ansj;

int main() {
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++) {
		int sum  = 0, ans = 0;
		scanf("%d",&n);

		ansi = 0;
		int ii, jj, len = -1;

		ii = 0;
		for (int i = 1; i < n; i++) {
			scanf("%d",&a[i]);
			
			sum += a[i];
			ans = max(ans, sum);
			
			a[i] += a[i-1];
			
			if (sum >= 0 and sum == ans) {
				if (i-ii > len) {
					len = i - ii;
					ansi = ii;
					ansj = i;
				}
			}
			if (sum < 0) {
				sum = 0;
				ii = i;
			}
		}

		printf("blblbl (%d,%d)\n",ansi,ansj);

		if (!ans) printf("Route %d has no nice parts\n",tt);
		else {
			ll len = -1;
			ansi, ansj;
			for (int i = 1; i < n; i++)
				for (int j = 1; j < n; j++)
					if (a[j] - a[i-1] == ans and (j-i) > len) {
						len = j-i;
						ansi = i;
						ansj = j;
					}
			printf("The nicest part of route %d is between stops %d and %d\n",tt,ansi,ansj+1);
		}
	}

	return 0;
}
