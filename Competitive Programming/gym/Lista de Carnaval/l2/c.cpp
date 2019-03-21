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

int n, m, a[N];

ll maxPages(int k) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += max(0,a[i] - i/(k+1));
	}

	return sum;
}

int bs(int l, int r) {
	if (l == r) return maxPages(l) >= m ? l : maxPages(l+1) >= m ? l+1 : -1;

	int mid = (l+r)/2;
	ll x = maxPages(mid);
	
	if (x == m) return mid;
	if (x < m) return bs(mid+1,r);
	return bs(l,mid-1);
}

int main() {
	scanf("%d%d",&n,&m);

	for (int i = 0; i < n; i++) scanf("%d",&a[i]);
	
	sort(a,a+n,greater<ll>());

	int id = bs(0,n-1);
	
	cout << (id == -1 ? -1 : id+1) << endl;
	return 0;
}
