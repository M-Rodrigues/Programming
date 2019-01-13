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

int R, C, H, V;
int grid[N][N];


int main() {
	int T;
	scanf("%d",&T);
	for (int t = 1; t <= T; t++) {
		cl(grid, 0);

		scanf("%d%d%d%d",&R,&C,&H,&V);
		for (int i = 0; i < R; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < C; j++) {
				if (s[j] == '@') grid[i][j] = 1;
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%d",grid[i][j]);
			}
			printf("\n");
		}
		printf("\n");

	
		for (int i = 1; i < R; i++)
			grid[i][0] += grid[i-1][0];
		for (int i = 1; i < C; i++)
			grid[0][i] += grid[0][i-1];

		for (int i = 1; i < R; i++)
			for (int j = 1; j < C; j++)
				grid[i][j] +=  - grid[i-1][j-1] + grid[i-1][j] + grid[i][j-1];

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%d",grid[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		
		for (int h = 0; h < R-1; h++) {
			for (int v = 0; v < C-1; v++) {
				int a1, a2, a3, a4;
				if (h == v == 0) {
					a1 = grid[h][v];
					a2 = grid[h][C-1] - a1;
					a3 = grid[R-1][v] - a1;
					a4 = grid[R-1][C-1] - a2 - a3 + a1;
				}
				if (h == 0 and v != 0) {
					a1 = grid[h][v] - grid[h][v-1];
					a2 = grid[h][R-1] - a1;
					a3 = grid[R-1][v] - a1;
					a4 = grid[R-1][C-1] - a2 - a3 + a1;
				}
				if (h != 0 and v == 0) {
					a1 = grid[h][v] - grid[h-1][v];
					a2 = grid[h][R-1] - a1;
					a3 = grid[R-1][v] - a1;
					a4 = grid[R-1][C-1] - a2 - a3 + a1;
				}
					
				
			}
		}

		string s;
		printf("Case #%d: %s\n",t,s.c_str());
	}
	return 0;
}
