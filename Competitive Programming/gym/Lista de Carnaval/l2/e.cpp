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

int sum, n;
vector<pii> arr;
vi ans;

int main() {
	cin >> n;
	arr.assign(n, {0,0});

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		arr[i] = {x,i};
		sum += x;
	}

	sort(arr.begin(), arr.end());

	for (auto p : arr) {
		printf("%d :: %d\n",p.st,p.nd);
	}


	for (int i = 0; i < n; i++) {
		int target = sum - arr[i].st;
		
		if (target % 2 == 0) {
			target /= 2;

			auto p1 = lower_bound(arr.begin(), arr.end(), target, [](pii p, int v) {
				return p.st < v;
			});

			auto p2 = upper_bound(arr.begin(), arr.end(), 2, [](int v, pii p) {
				return v < p.st;
			});
			
			if (p2 == arr.end()) { // não eh good array

			} else { // encontrou
				if (p1->nd == i and p2->nd == i) { // eh o mesmo cara

				} else {
					if (p1->nd != i) { // yay!
						ans.pb(p1->nd);
					}
				}
			}
		}
	}

	cout << ans.size() << endl;
	for (int x : ans) cout << x << " "; cout << endl;
	

	return 0;
}
