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

int n, p;
set<string> req;
int main() {
	scanf("%d%d\n",&n,&p);
	int t = 1;
	while (n+p) {
		for (int i = 0; i < n; i++) {
			string aux;
			getline(cin, aux);
			//cout << aux << endl;
		}

		int ans_r = 0;
		double ans_d = 0;
		string ans_name = "";
		while (p--) {
			string name; 
			getline(cin, name);
			//cout << name << endl;
			
			double d; int r;
			scanf("%lf%d\n",&d,&r);

			if (r > ans_r or (r == ans_r and d > ans_d)) {
				ans_r = r;
				ans_d = d;
				ans_name = name;
			}

			while (r--) {
				string auxx; 
				getline(cin, auxx);
			}
		}

		printf("RFP #%d\n%s\n\n",t,ans_name.c_str());
		scanf("%d%d\n",&n,&p);
		t++;
	}
	return 0;
}
