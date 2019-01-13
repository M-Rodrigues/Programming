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

int pai[N], size[N], n, q, x, y, maxSize, minSize;
multiset<int> s;

int find(int x) {
	return (pai[x] == x) ? x : pai[x] = find(pai[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;

	if (size[a] > size[b]) swap(a,b);
	pai[a] = b;
	size[b] += size[a];

	maxSize = max(maxSize, size[b]);
}

int main() {
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; i++) pai[i] = i, size[i] = 1, s.insert(1);

	while (q--) {
		scanf("%d%d",&x,&y);
		int a = find(x);
		int b = find(y);
		if (a != b) {


			s.erase(s.find(size[a]));
			s.erase(s.find(size[b]));
			size[a] += size[b];
			size[b] = 0;
			s.insert(size[a]);

			pai[find(y)] = find(x);

		}
		multiset<int>::iterator end = s.end();
		end--;
		printf("%d\n",(int)(*end-*s.begin()));
	}
	
	return 0;
}
