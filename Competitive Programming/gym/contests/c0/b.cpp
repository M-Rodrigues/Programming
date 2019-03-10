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

int k, n;
ll h[N];

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		h[i] += h[i-1];
	}

	int sum = INT_MAX, index = 0;

	for (int i = 1; i <= n-k+1; i++) {
		if (h[i+k-1] - h[i-1] < sum) {
			sum = h[i+k-1] - h[i-1];
			index = i;
		}
	}

	printf("%d\n",index);
	return 0;
}
