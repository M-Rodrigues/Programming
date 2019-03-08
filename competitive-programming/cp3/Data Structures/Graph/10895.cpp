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

int n, m;
map<int, set<pii>> mt;
vi col;

int main() {
	
	while (cin >> n >> m) {
		mt.clear();

		for (int i = 0; i < n; i++) {
			int nn; cin >> nn;
			
			col.assign(nn, 0);
			for (int j = 0; j < nn; j++) cin >> col[j];
		
			for (int j = 0; j < nn; j++) {
				int aux; cin >> aux;

				mt[col[j]].insert({i+1, aux});
			}
		}

		printf("%d %d\n",m,n);
		for (int i = 0; i < m; i++) {
			if (mt.find(i+1) != mt.end()) {
				set<pii> row = mt[i+1];
				
				printf("%d ",(int)row.size());
				int k = 0;
				for (pii p : row) {
					printf("%d%c",p.st,(k==(int)row.size()-1 ? '\n': ' ')); k++;
				}
				k = 0;
				for (pii p : row) {
					printf("%d%c",p.nd,(k==(int)row.size()-1 ? '\n': ' ')); k++;
				}
			} else {
				printf("0\n\n");
			}
		}
	}
	return 0;
}
