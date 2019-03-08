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

int n, m, k, x, y, t, memo[2*N][30][30], maca[2*N][30][30];

int dp(int x, int y, int t) {
	if (memo[t][x][y] != -1) return memo[t][x][y];
	if (x < 1 or x > n or y < 1 or y > m or t > 2*k) return memo[t][x][y] = 0;
	
	int d1 = dp(x,y,t+1);
	int d2 = dp(x+1,y,t+1);
	int d3 = dp(x+1,y+1,t+1);
	int d4 = dp(x,y+1,t+1);
	int d5 = dp(x-1,y+1,t+1);
	int d6 = dp(x-1,y,t+1);
	int d7 = dp(x-1,y-1,t+1);
	int d8 = dp(x,y-1,t+1);
	int d9 = dp(x+1,y-1,t+1);
	
	return memo[t][x][y] = maca[t][x][y] + max({d1,d2,d3,d4,d5,d6,d7,d8,d9});
}

int main() {
	while (scanf("%d%d%d",&n,&m,&k) and n and m and k) {
		cl(maca, 0);
		cl(memo, -1);

		for (int i = 0; i < k; i++) {
			scanf("%d%d%d",&x,&y,&t);
			maca[t][x][y]++;
		}
		
		scanf("%d%d",&x,&y);
		
		printf("%d\n",dp(x,y,0));
	}
	return 0;
}
