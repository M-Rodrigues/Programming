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

int n, x;
ll adj[N][N], sum;
vector<int> nodes;
stack<int> removed;
stack<ll> ans;
 
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%lld",&adj[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d",&x);
		removed.push(x);
	}

	while (!removed.empty()) {
		int u = removed.top();
		removed.pop();
		nodes.pb(u);
		sum = 0;

		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][u] + adj[u][j]);
		
		for (int i : nodes)
			for (int j : nodes)
				sum += adj[i][j];

		ans.push(sum);
	}


	while (!ans.empty()) {
		printf("%lld ",ans.top());
		ans.pop();
	}
	printf("\n");

	return 0;
}
