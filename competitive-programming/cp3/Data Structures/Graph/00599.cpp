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

int arr[26];
string input;

int main() {
	int t; cin >> t;
	while (t--) {
		cl(arr, -1);

		int ne = 0;
		while (cin >> input, input[0] != '*') {
			int a = input[1] - 'A';
			int b = input[3] - 'A';
			arr[a]=1; arr[b]=1; ne++;
		}

		int na = 0, nv;
		cin >> input;
		nv = ((int)input.size()+1)/2;

		for (int i = 0; i < input.size(); i+=2) {
			int a = input[i] - 'A';
			if (arr[a] == -1) na++;
		}
		
		printf("There are %d tree(s) and %d acorn(s).\n",nv-ne-na,na);
	}
	return 0;
}
