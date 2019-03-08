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

int a[N], n;
ll sum;

int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
		sum += a[i];
	}

	cout << sum << endl;

	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == sum - a[i]) k++;
	}

	printf("%d\n",k);
	for (int i = 0; i < n; i++) {
		if (a[i] == sum - a[i]) printf("%d ",i+1);
	}
	printf("\n");

	return 0;
}
