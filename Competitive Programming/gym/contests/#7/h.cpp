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
const int N = 2e2+5;

int n, q, c, xi, yi, xf, yf, s, t;
ll sky[N][N][20];

int main() {
	scanf("%d%d%d",&n,&q,&c);

	while(n--) {
		scanf("%d%d%d",&xi,&yi,&s);
		for (int i = 0; i <= c; i++)
			sky[xi][yi][i] += (s+i) % (c+1);
	}

	for (int i = 0; i < 20; i++)
		for (int x = 1; x < N; x++)
			for (int y = 1; y < N; y++)
				sky[x][y][i] += sky[x-1][y][i] + sky[x][y-1][i] - sky[x-1][y-1][i];
 			

	while (q--) {
		scanf("%d%d%d%d%d",&t,&xi,&yi,&xf,&yf);
		t %= (c+1);
		printf("%lld\n",sky[xf][yf][t] - sky[xi-1][yf][t] - sky[xf][yi-1][t] + sky[xi-1][yi-1][t]);
	}

	return 0;
}
