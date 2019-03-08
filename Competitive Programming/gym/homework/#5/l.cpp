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

int n, m, cnt, inc[N];
string s;
map<string, int> id;
map<int, string> idt;
vi adj[N], ts;
// queue<int> q;
priority_queue<int, vi, greater <int>> q;

int main() {
	int t = 0;
	while (cin >> n) {
		t++;
		cl(inc, 0);
		id.clear();
		idt.clear();
		ts.clear();
		cnt = 0;
		for (int i = 0; i < N; i++) adj[i].clear();

		for (int i = 0; i < n; i++) {
			cin >> s;
			if (!id.count(s)) {
				id[s] = ++cnt;
				idt[cnt] = s;
			}
		}

		cin >> m;
		while (m--) {
			string s1, s2;
			cin >> s1 >> s2;
			
			adj[id[s1]].pb(id[s2]);
			inc[id[s2]]++;
		}

		for (int i = 1; i <= n; i++) if (inc[i] == 0) q.push(i);

		while (!q.empty()) {
			int u = q.top(); q.pop();
			// int u = q.front(); q.pop();
			for (int v : adj[u])
				if (inc[v] > 0 and --inc[v] == 0)
					q.push(v);
			ts.pb(u);
		}

		printf("Case #%d: Dilbert should drink beverages in this order: ",t);
		for (int i = 0; i < ts.size(); i++) 
			printf("%s%s",idt[ts[i]].c_str(),(i+1==ts.size()?".\n":" "));
		printf("\n");
	}
	return 0;
}
