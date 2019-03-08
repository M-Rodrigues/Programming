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

class SegmentTree {
public:
	int n;
	vi A;
	vector<pii> st;
	SegmentTree(const vi &_A) {
		A = _A; n = (int)_A.size();
		st.assign(4*n, {0,0});
		build(1, 0, n-1);
	}

	void build(int p, int L, int R) {
		if (L == R) {
			st[p] = {A[L], 1}; return;
		}

		int mid = (L+R)/2;
		build(2*p, L, mid);
		build(2*p+1, mid+1, R);

		pii p1 = st[2*p];
		pii p2 = st[2*p+1];

		if (p1.st == p2.st) {
			st[p] = {p1.st, p1.nd+p2.nd}; return;
		}

		if (p1.nd > p2.nd) {
			st[p] = p1;
		} else {
			st[p] = p2;
		}

	}

	int query(int i, int j) {
		return query(1, 0, n-1, i, j).nd;
	}

	pii query(int p, int L, int R, int i, int j) {
		if (i > R or j < L) return {0, 0};
		if (L >= i and R <= j) return st[p];

		int mid = (L+R)/2;
		pii p1 = query(2*p, L, mid, i, j);
		pii p2 = query(2*p+1,mid+1, R, i, j);

		if (p1.nd == 0) return p2;
		if (p2.nd == 0) return p1;

		if (p1.st == p2.st) return {p1.st, p1.nd+p2.nd};
		return p1.nd > p2.nd ? p1 : p2;
	}
};

int main() {
	int n, q;
	while (cin >> n, n) {
		cin >> q;

		vi arr;
		arr.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		SegmentTree s(arr);


		while (q--) {
			int i, j;
			cin >> i >> j;
			cout << s.query(i, j) << endl;
		}
	}


	return 0;
}
