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

int st[4*N] , v[N] = {3, 4, 5, 2, 1, 6, 7, 4, 3}, lz[4*N];

void build(int p, int l, int r) {
  if (l == r) { st[p] = v[l]; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p] = min(st[2*p], st[2*p+1]); // RMQ -> min/max, RSQ -> +
}

void push(int p, int l, int r) {
  if (lz[p]) {
    st[p] = lz[p];
    // RMQ -> update: = lz[p],         increment: += lz[p]
    // RSQ -> update: = (r-l+1)*lz[p], increment: += (r-l+1)*lz[p]
    if(l!=r) lz[2*p] = lz[2*p+1] = lz[p]; // update: =, increment +=
    lz[p] = 0;
  }
}

ll query(int p, int l, int r, int i, int j) {
  push(p, l, r);
  if (r < i or l > j) return INF; // RMQ -> INF, RSQ -> 0
  if (l >= i and r <= j) return st[p];
  return min(query(2*p, l, (l+r)/2, i, j),
             query(2*p+1, (l+r)/2+1, r, i, j));
  // RMQ -> min/max, RSQ -> +
}

void update(int p, int l, int r, int i, int j, int v) {
  push(p, l, r);
  if (r < i or l > j) return;
  if (l >= i and r <= j) { lz[p] = v; push(p, l, r); return; }
  update(2*p, l, (l+r)/2, i, j, v);
  update(2*p+1, (l+r)/2+1, r, i, j, v);
  st[p] = min(st[2*p], st[2*p+1]); // RMQ -> min/max, RSQ -> +
}

int main() {
	build(1,0,8);


	for (int i = 0 ; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {
			printf("(%d, %d) -> %lld\n",i,j,query(1,i,j,0,8));
		}
	}
	return 0;
}
