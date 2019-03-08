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


int p[N], sz[N];

void clearTS() {
	for (int i = 0; i < N; i++) p[i] = i, sz[i] = 0;
}

int find(int i) { i == p[i] ? i : p[i] = find(p[i]); }

void unite(int i, int j) {
	int x = find(i), y = find(j);
	if (x != y) {		
		if (sz[x] > sz[y]) p[y] = x;
		else {
			p[x] = y;
			if (sz[x] == sz[y]) sz[y]++;
		}
	}
}

int main() {
	int t; cin >> t; while (t--) {
		int n; scanf("\n%d\n",&n);

		clearTS();

		int ns = 0, nf = 0;
		while (1) {
			string s; getline(cin, s);
			if (s.size() == 0 or !(s[0] == 'c' or s[0] == 'q')) break;
			
			char op; int x, y; 
			sscanf(s.c_str(),"%c %d %d",&op,&x,&y);

			if (op == 'c') unite(x, y);
			else (find(x) == find(y)) ? ns++ : nf++;
		}

		printf("%d,%d\n\n",ns,nf);
	}
	return 0;
}
