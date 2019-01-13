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

int z[N];
vi p;

void z_func(string &s) {
    int x, y; x = y = 0;

    z[0]=0;
    for (int i = 1; i < s.size(); i++) {
        z[i] = max(0,min(y-i,z[i-x]));

        while (z[i]+i < s.size() and s[z[i]] == s[z[i] + i])
            x = i, z[i]++, y = z[i]+i;
    }
}

int main() {
	int t; scanf("%d",&t);
	while (t--) {
		cl(z, 0);
		p.clear();

		string a, b;
		cin >> a >> b;

		a = b + "$" + a;
		z_func(a);
		for (int i = 0 ; i < a.size(); i++) {
			if (z[i] == b.size()) p.pb(i-b.size());
		}

		if (p.size()==0) printf("Not Found\n");
		else {
			printf("%d\n",(int)p.size());
			for (int v : p) printf("%d ",v); printf("\n");
		}

		printf("\n");
	}
	return 0;
}
