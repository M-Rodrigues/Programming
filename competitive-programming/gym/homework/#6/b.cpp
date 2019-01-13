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

ll p1, p2, sum, memo[N][N];
int cards[N], n;

ll solve(int i, int j) {
	if (~memo[i][j]) return memo[i][j];
	if (i > j) return memo[i][j] = 0;

	ll l, r;
	ll p2_l, p2_r;

	if (cards[i+1] >= cards[j]) {
		p2_l = i+1;
		l = cards[i] + solve(i+2,j);
	} else {
		p2_l = j;
		l = cards[i] + solve(i+1,j-1);
	}

	if (cards[i] >= cards[j-1]) {
		p2_r = i;
		r = cards[j] + solve(i+1,j-1);
	} else {
		p2_r = j-1;
		r = cards[j] + solve(i,j-2);
	}

	return memo[i][j] = max(l,r);
}

int main() {
	int t = 0;
	while(scanf("%d",&n) and n) {
		t++;
		cl(memo, -1);
		sum = 0;
		
		for (int i = 0; i < n; i++) scanf("%d",&cards[i]), sum += cards[i];

		p1 = solve(0, n-1);
		p2 = sum - p1;

		printf("In game %d, the greedy strategy might lose by as many as %lld points.\n",t,p1-p2);
	}
	return 0;
}