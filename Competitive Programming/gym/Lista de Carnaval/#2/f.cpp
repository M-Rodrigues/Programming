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
const int N = 2e5+5;

int n, a[N], l, r, q, in[N];

int main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];

	while (q--) {
		cin >> l >> r;
		in[l-1]++;
		in[r]--;
	}

	for (int i = 0; i < n; i++) printf("%d ",in[i]);
	printf("\n");

	int size = 0;
	for (int i = 1; i < N; i++) {
		in[i] += in[i-1];
		if (in[i] > 0) size++; 
	}
	
	for (int i = 0; i < n; i++) printf("%d ",in[i]);
	printf("\n");

	if (in[0] != 0) size++;

	sort(a, a+n, greater<int>());

	ll ans = 0;
	for (int i = 0; i < size; i++) ans += a[i];

	cout << ans << endl;

	return 0;
}
