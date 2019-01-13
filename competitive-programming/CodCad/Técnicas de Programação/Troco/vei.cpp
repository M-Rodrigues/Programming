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

int n, m, dp[N];
vi coins;

int solve(int x, vi & c) {
    if (x == 0) return 1;
    if (x < 0 ) return 0;
    if (dp[x] >= 0) return dp[x];
    
    for (int v : c) if(solve(x-v,c)) return dp[x-v] = 1;
    
    return dp[x] = 0;
}

int soma(int x) {
	static int n = 0;
	n++;
	return x+n;
}

class teste {
public:
	static int n;

	int soma(int x) {
		n++;
		return x+n;
	}
};

int teste::n = 0;



int main() {
    // cin >> n >> m;
	// cl(dp, -1);
	
    // while (n--) {
    //     int a;
    //     cin >> a;
    //     coins.pb(a);
    // }
    
    // cout << (solve(m,coins) ? "S" : "N") << endl;

	int a = soma(10);
	int b = soma(10);
	int c = soma(10);
	int d = soma(10);

	// cout << a << endl << b << endl << c << endl << d << endl;

	teste A, B;

	cout << A.soma(10) << endl;
	cout << B.soma(10) << endl;

	return 0;
}


