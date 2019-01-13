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

int n;
ll memo[N];

ll solve(int n) {
	if (n < 0) return 0;
	if (~memo[n]) return memo[n];
	if (n == 0) return memo[n] = 1;
	return solve(n-1) + solve(n-2) + solve(n-3);
}

int main() {
	cl(memo, -1);
	
	scanf("%d",&n);
	printf("%lld\n",solve(n));

	return 0;
}
