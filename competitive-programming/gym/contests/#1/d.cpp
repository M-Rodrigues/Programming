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

const int A = 1234567;
const int B = 123456;
const int C = 1234;

string solve(int n) {
	for (int a = n/A; a >= 0; a--)
		for (int b = (n - a*A)/B; b >= 0; b--)
			for (int c = (n - a*A - b*B)/C; c >= 0; c--)
				if (a*A + b*B + c*C == n)
					return "YES";
	return "NO";
}

int main() {
	ll n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
