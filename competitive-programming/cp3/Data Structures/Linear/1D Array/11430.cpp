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

int n, k, m;
map<char, int> l;
char c;

int main() {
	scanf("%d\n",&n);
	while (n--) {
		l.clear();

		scanf("%d\n",&k);
		while (k--) {
			scanf("%c ",&c);
			scanf("%d\n",&l[c]);
		}

		scanf("%d\n",&m);
		double total = 0;
		while (m--) {
			string s;
			getline(cin, s);

			for (int i = 0; i < s.size(); i++)
				total += (double)l[s[i]]/100.0;
		}

		printf("%.2lf$\n",total);
	}
	return 0;
}
