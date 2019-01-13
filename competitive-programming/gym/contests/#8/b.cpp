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
const int N = 1e5+5;

ll dp[N], v[N];
 
int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		int p;
		scanf("%d",&p);
		v[p]++;
	}

	dp[0] = 0;
	dp[1] = v[1];
	for (int i = 2; i < N; i++) 
		dp[i] = max(dp[i-1], dp[i-2] + i*v[i]);
	
	printf("%lld\n",dp[N-1]);
	return 0;
}
