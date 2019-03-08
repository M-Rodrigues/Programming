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

int n, m, q, t, pai[2*N], size[2*N];
map<string, int> cod;

int find(int x) {
	return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	
	if (a==b) return;

	if (size[a] > size[b]) swap(a,b);
	size[b] += size[a];
	pai[a] = b;
}

int main() {
	scanf("%d%d%d",&n,&m,&q);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		cod[s] = 2*i;
	}
	
	for (int i = 0; i < 2*N; i++) pai[i] = i, size[i] = 1;	

	while (m--) {
		int x, y;
		string a, b;
		cin >> t >> a >> b;
		
		x = cod[a]; y = cod[b];

		if (t == 1) {
			if (find(x) == find(y+1) or find(y) == find(x+1)) printf("NO\n");
			else {
				unite(x,y);
				unite(x+1,y+1);
				printf("YES\n");
			}
		} else {
			if (find(x) == find(y)) printf("NO\n");
			else {
				unite(x,y+1);
				unite(x+1,y);
				printf("YES\n");
			}
		}
	}

	while (q--) {
		string a, b;
		cin >> a >> b;

		int x = cod[a];
		int y = cod[b];

		if (find(x) == find(y)) printf("1\n");
		else if (find(x+1) ==find(y) or find(x) == find(y+1)) printf("2\n");
		else printf("3\n");
	}	

	return 0;
}
