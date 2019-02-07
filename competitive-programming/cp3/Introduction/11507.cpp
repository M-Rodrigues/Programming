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

int main() {
	map<string, map<string, string>> next;

	next["+x"]["+y"] = "+y";
	next["+x"]["-y"] = "-y";
	next["+x"]["+z"] = "+z";
	next["+x"]["-z"] = "-z";
	
	next["-x"]["+y"] = "-y";
	next["-x"]["-y"] = "+y";
	next["-x"]["+z"] = "-z";
	next["-x"]["-z"] = "+z";

	next["+y"]["+y"] = "-x";
	next["+y"]["-y"] = "+x";
	next["+y"]["+z"] = "+y";
	next["+y"]["-z"] = "+y";

	next["-y"]["+y"] = "+x";
	next["-y"]["-y"] = "-x";
	next["-y"]["+z"] = "-y";
	next["-y"]["-z"] = "-y";

	next["+z"]["+y"] = "+z";
	next["+z"]["-y"] = "+z";
	next["+z"]["+z"] = "-x";
	next["+z"]["-z"] = "+x";

	next["-z"]["+y"] = "-z";
	next["-z"]["-y"] = "-z";
	next["-z"]["+z"] = "+x";
	next["-z"]["-z"] = "-x";

	
	int n;
	while (cin >> n, n) {
		n--;
		string head = "+x";
		while (n--) {
			string move;
			cin >> move;

			if (move != "No")
				head = next[head][move];
		}

		printf("%s\n",head.c_str());
	}
	return 0;
}
