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

int n, m, a, b, t;
string s, grid[N];

int dr[] = {+1, +1, +0, -1, -1, -1, +0, +1};
int dc[] = {+0, +1, +1, +1, +0, -1, -1, -1};

int floodfill(int r, int c, char c1, char c2) {
	if (r < 0 or r >= n or c < 0 or c >= m) return 0;
	if (grid[r][c] != c1) return 0;
	int ans = 1;
	grid[r][c] = c2;
	for (int d = 0; d < 8; i++) 
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	return ans;
}

int main() {
	scanf("%d",&t);
	while (t--) {
		n = 0;
		while (getline(cin, s)) {
			// if (s[0] == '\0') break;
			if (s[0] == 'L' or s[0] == 'W') { // reading data
				grid[n] = s; n++;
				m = s.size();
 			} else {
				int a, b;
				sscanf(s.c_str(),"%d %d",&a,&b);

			}	
		}
		// for (int i = 0; i < n; i++) {
		// 	cout << grid[i] << endl;
		// }
	}
	return 0;
}
