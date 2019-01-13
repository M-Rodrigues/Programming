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
const int N = 1e5+5;

ll st[4*N], lazy[4*N];

void update(int n, int i, int j, int a, int b, int v){ 
	int mid = (i + j)/2;
	
	if (lazy[n]) {		
		st[n] = lazy[n]*(j - i + 1);

		if(i != j){
			lazy[2*n+1] = lazy[n];
			lazy[2*n] = lazy[n];
		}
		
		lazy[n] = 0;
	}
	
	if (i > j or i > b or a > j) return;
	
	if (a <= i and j <= b){ 
		st[n] = v*(j-i+1);
	
		if(i != j){
			lazy[2*n+1] = v;
			lazy[2*n] = v;
		}
	} else {
		update(2*n, i, mid, a, b, v);
		update(2*n+1, mid+1, j, a, b, v);
		
		st[n] = st[2*n] + st[2*n+1]; 
	}
}

ll query(int n, int i, int j, int a, int b){
	if (lazy[n]){
		st[n] = lazy[n]*(j - i + 1);
		
		if(i != j){ 
			lazy[2*n+1] = lazy[n];
			lazy[2*n] = lazy[n];
		}
		
		lazy[n] = 0; 
	}
	
	if (i > j or i > b or a > j) return 0; 
	
	if (a <= i and j <= b) return st[n];
	else { 
		int mid = (i + j)/2;
		
		ll soma_esquerda = query(2*n, i, mid, a, b);
		ll soma_direita  = query(2*n+1, mid+1, j, a, b);
		
		return soma_esquerda + soma_direita;
	}
}

int main() {
	int n, q;
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; i++) {
		int aux;
		scanf("%d",&aux);
		update(1,1,n,i,i,aux);
	}

	while (q--) {
		int op, a, b;
		scanf("%d%d%d",&op,&a,&b);

		if (op == 1) {
			int k; scanf("%d",&k);
			update(1,1,n,a,b,k);
		} else {
			printf("%lld\n",query(1,1,n,a,b));
		}
	}
	

	return 0;
}
