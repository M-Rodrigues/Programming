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
const int N = 1e6+5;

int n,a,b,ans,mvs,up,down,ans_x,ans_y;
int vis[N];
vi adj[N], list_x, list_y;
set<pii> drift;
set<int> set_x, set_y;


map<int, piii> X, Y;

int main() {
	scanf("%d",&n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d",&a,&b);
		set_x.insert(a); set_y.insert(b);

		if (X.count(a) == 0) X[a] = {1,{b,b}};
		else {
			piii P = X[a];
			int qtde = P.st;
			int max_y = P.nd.nd;
			int min_y = P.nd.st;

			max_y = max(max_y,b);
			min_y = min(min_y,b);
			qtde++;

			X[a] = {qtde, {min_y,max_y}};
		}
		if (Y.count(b) == 0) Y[b] = {1,{a,a}};
		else {
			piii P = Y[b];
			int qtde = P.st;
			int max_y = P.nd.nd;
			int min_y = P.nd.st;

			max_y = max(max_y,a);
			min_y = min(min_y,a);
			qtde++;

			Y[b] = {qtde, {min_y,max_y}};
		}
		// printf("Y[%d] = (%d, (%d,%d))\n",b,Y[b].st,Y[b].nd.st,Y[b].nd.nd);
		// printf("X[%d] = (%d, (%d,%d))\n",a,X[a].st,X[a].nd.st,X[a].nd.nd);
	}

	for (int x : set_x) list_x.pb(x);
	for (int y : set_y) list_y.pb(y);

	// printf("X -> ");
	// for (int v : list_x) printf("%d ",v);
	// printf("\n");
	// printf("Y -> ");
	// for (int v : list_y) printf("%d ",v);
	// printf("\n");

	if (list_x.size() == 1) ans = 0;
	else if (list_y.size() == 1) ans = 0;
	else if (list_x.size() == 2 or list_y.size() == 2) {
		// Analisando X
		int pos = list_x[1];
		int last_pos = list_x[0];

		if (X[pos].st > 1) mvs = 2;
		else {
			if (X[last_pos].st == 1) {
				if (X[pos].nd.nd != X[last_pos].nd.nd) mvs = 1;
				else mvs = 0;
			} else {
				if (X[last_pos].nd.nd == X[pos].nd.nd) mvs = 1;
				else mvs = 2;

				if (X[last_pos].nd.st == X[pos].nd.st) mvs = 1;
				else mvs = 2;
			}
		}

		ans = mvs;
		mvs= 0;

		pos = list_y[1];
		last_pos = list_y[0];
		
		if (Y[pos].st > 1) mvs = 2;
		else {
			if (Y[last_pos].st == 1) {
				if (X[pos].nd.nd != Y[last_pos].nd.nd) mvs = 1;
				else mvs = 0;
			} else {
				if (Y[last_pos].nd.nd == Y[pos].nd.nd) mvs = 1;
				else mvs = 2;

				if (Y[last_pos].nd.st == Y[pos].nd.st) mvs = 1;
				else mvs = 2;
			}
		}

		ans = min(ans,mvs);
	} else {
		// Percorrendo em X e contando em Y
		mvs = 0;

		for (int i = 1; i < list_x.size(); i++) {

			if (i < list_x.size()-1) mvs += 2;
			else {
				int pos = list_x[i];
				int last_pos = list_x[i-1];
				
				if (X[pos].st == 1) {
					if (X[last_pos].nd.nd == X[pos].nd.nd) up = 1;
					else up = 2;
				} else up = 2;

				if (X[pos].st == 1) {
					if (X[last_pos].nd.st == X[pos].nd.st) down = 1;
					else down = 2;
				} else down = 2;

				db(up);db(down);
				mvs += min(up,down);
			}
		}
		ans = mvs;
		db(mvs);
		// Percorrendo em Y e contando em X
		mvs = 0;
		for (int i = 1; i < list_y.size(); i++) {

			if (i < list_y.size()-1) mvs += 2;
			else {
				int pos = list_y[i];
				int last_pos = list_y[i-1];
				
				if (Y[pos].st == 1) {
					if (Y[last_pos].nd.nd == Y[pos].nd.nd) up = 1;
					else up = 2;
				} else up = 2;

				if (Y[pos].st == 1) {
					if (Y[last_pos].nd.st == Y[pos].nd.st) down = 1;
					else down = 2;
				} else down = 2;

				db(up);db(down);
				mvs += min(up,down);
			}
		}
		db(mvs);
		ans = min(ans,mvs);
	}

	printf("%d\n",ans);
	return 0;
}
