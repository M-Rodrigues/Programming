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

	int n, t, v;
	string s;
	vector<string> times[N];
	priority_queue<pair<int, string>> pq;

	int main() {
		scanf("%d%d",&n,&t);

		for (int i = 0; i < n; i++) {
			// scanf("%s%d",&s,&v);
			cin >> s >> v;
			pq.push(mp(v,s));
		}

		while (!pq.empty()) {
			for (int i = 1; i <= t; i++) if (!pq.empty()) {
				times[i].pb(pq.top().nd);
				pq.pop();
			}
		}
		for (int i = 1; i <= t; i++) {
			sort(times[i].begin(), times[i].end());
			
			printf("Time %d\n",i);
			for (string s : times[i]) printf("%s\n",s.c_str());
			printf("\n");
		}
		


		return 0;
	}
