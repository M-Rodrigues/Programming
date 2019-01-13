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

int size[N], pai[N];
int n, m, i, q, op;
string s, s1, s2;
map<string, int> id;

int find(int x) {
	return (pai[x] == x) ? x : pai[x] = find(pai[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (size[a] > size[b]) swap(a,b);
	size[b] += size[a];
	pai[a] = b;
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1; i <= n; i++) {
		cin >>s;
		id[s] = 2*i;
	}

	for (int i = 1; i <= n; i++) pai[i] = i, size[i] = 1;

	while (m--) {
		cin>>op>>s1>>s2;
		int a = id[s1];
		int b = id[s2];

		if (op == 1) { // fazer s1 sinonimo de s2;
			if (a == b + 1) {
				printf("NO\n");
			} else {
				printf("YES\n");
				unite(a,b);
				unite(a+1,b+1);
			}
		} else { // fazer s1 antonimo de s2;
			if (a == b) {
				printf("NO\n");
			} else {
				printf("YES\n");
				unite(a,b+1);
				unite(a+1,b);
			}
		}
	}

	while (q--) {
		cin>>s1>>s2;
		
		int a = find(id[s1]);
		int b = find(id[s2]);

		if (a == b) printf("1\n");
		else if (a == b+1 or a+1 == b) printf("2\n");
		else printf("3\n");
	}

	return 0;
}
