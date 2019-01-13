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

int T, n, t;
vi even, odd, v;

vi troubleSort(vi L) {
	bool ok = false;
	while (!ok) {
		ok = true;
		for (int i = 0; i < L.size() - 2; i++) if (L[i] > L[i+2]) ok = false, swap(L[i],L[i+2]);
	}
	return L;
}

void print(vi vv) {
	for (int v : vv) printf("%d ",v);
	printf("\n");
}

int main() {
	scanf("%d",&T);
	while (T--) {
		t++;
		even.clear();
		odd.clear();
		v.clear();

		scanf("%d",&n);

		for (int i = 0; i < n; i++) {
			int a; scanf("%d",&a);

			v.pb(a);

			if (i%2) odd.pb(a);
			else even.pb(a);
		}

		sort(odd.begin(),odd.end());
		sort(even.begin(),even.end());

		v.clear();
		for (int i = 0; i < n; i++)
			if (i%2)
				v.pb(odd[i/2]);
			else
				v.pb(even[i/2]);

		int pos = 0;
		bool ok = true;

		for (int i = 0; i < n - 1; i++) {
			if (v[i] > v[i+1]) 
				ok = false, pos = i;

			if (!ok) break;
		}

		printf("Case #%d: ",t);
		if (ok) printf("OK\n");
		else printf("%d\n",pos);

	}
	return 0;
}
