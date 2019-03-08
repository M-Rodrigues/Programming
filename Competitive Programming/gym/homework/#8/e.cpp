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

int n, q, op, a, b;
ll arr[N], bit0[N], bit1[N], bit2[N];

void add(int val, int x, ll bit[]) {
	for (; x < N; x += x&(-x)) bit[x] += val;
}

ll query(int x, ll bit[]) {
	ll ans = 0;
	for (; x > 0; x -= x&(-x)) ans += bit[x];
	return ans;
}

void printArray() {
	for (int i = 1; i <= n; i++) printf("%d ",i); printf("\n");
	for (int i = 1; i <= n; i++) printf("%lld ",bit0[i]); printf("\n");
	for (int i = 1; i <= n; i++) printf("%lld ",bit1[i]); printf("\n");
	for (int i = 1; i <= n; i++) printf("%lld ",bit2[i]); printf("\n\n");
}

void customAdd(int val, int x) {
	printf("-begin customAdd()-\n");
	if (x != 0) {

		if (val == 1) {
			for (; x < N; x += x&(-x)) {
				printf("-");
				add(-1,x,bit0);
			}
		} else { 
			for (; x < N; x += x&(-x)) {
				
			}
		}
	}
}

int main() {
	scanf("%d%d",&n,&q);

	for (int i = 1; i <= n; i++) add(1,i,bit0);
	printArray();
	
	while (q--) {
		db(q);
		scanf("%d%d%d",&op,&a,&b); a++; b++;
		db(op _ a _ b);
		if (op == 1) { // query entra a e b
			printf("Multiplos de 3 entre %d e %d: ",a,b);
			printf("%lld\n",query(b,bit0)-query(a-1,bit0));
		} else { // aumentar em 1 entre a e b
			printf("Aumentando 1 em todo mundo até %d\n",b);
			customAdd(1,b);
			printf("Diminuindo 1 em todo mundo até %d\n",a-1);
			customAdd(-1,a-1);
		}
		printArray();
	}

	return 0;
}
