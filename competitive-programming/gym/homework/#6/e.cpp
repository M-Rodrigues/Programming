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

int n, m, x;
pii memo[N]; 
vi coinValue;

bool isQB(int n) {
	while (n != 0) {
		int uni = n%10;
		if (uni != 0 and uni != 1) return false;
		n /= 10;
	}
	return true;
}

pii dp(int n) {
	if (n == 0) return memo[n] = mp(0,0);
	if (n < 0) return mp(INF,0);

	if (memo[n].st != -1) return memo[n];

	int total = INF;
	int last_val = 0;
	for (int i = 0; i < coinValue.size(); i++) {
		int aux = dp(n - coinValue[i]).st; 
		if (aux <= total) {
			total = aux;
			last_val = i; 
		}
	}	
	return memo[n] = mp(1 + total,last_val);
}

int main() {
	scanf("%d",&x);

	// calcular todos quasi binary numbers
	for (int i = 1; i <= N; i++) if (isQB(i)) coinValue.pb(i);
	cl(memo, -1);

	printf("%d\n",dp(x).st);
	while (x != 0) {
		printf("%d ",coinValue[dp(x).nd]);
		x -= coinValue[dp(x).nd];
	}
	printf("\n");
	
	return 0;
}
