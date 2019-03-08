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

vi n1, n2, n3;

int main() {
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d",&x);
		if (x < 0) {
			if (n1.size() == 0) n1.pb(x);
			else n2.pb(x);
		} else if (x == 0) n3.pb(x);
		else n2.pb(x);
	}

	int n_imp = 0;
	for (int x : n2) if (x < 0) n_imp++;
	if (n_imp % 2 == 1) {
		for (int i = 0; i < n2.size(); i++) {
			if (n2[i] < 0) {
				n3.pb(n2[i]);
				n2.erase(n2.begin()+i);
				break;
			}
		}
	}

	printf("%d ",(int)n1.size());
	for (int x : n1) printf("%d ",x); 
	printf("\n");

	printf("%d ",(int)n2.size());
	for (int x : n2) printf("%d ",x); 
	printf("\n");

	printf("%d ",(int)n3.size());
	for (int x : n3) printf("%d ",x); 
	printf("\n");


	return 0;
}
