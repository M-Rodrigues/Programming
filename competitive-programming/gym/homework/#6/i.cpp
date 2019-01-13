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

int M, D, c, aux, total, menor;
bitset<50> chaves[50];

void dp(int i, vi escolhidos, bitset<50> total) {
	if (i == D) {
		if (total.count() >= M) menor = min(menor, (int)escolhidos.size());
	} else {
		dp(i+1, escolhidos, total);

		escolhidos.pb(i);
		total |= chaves[i];
		dp(i+1, escolhidos, total);
	}
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&M,&D);
		cl(chaves, 0);
		
		for (int i = 0; i < D; i++) {
			scanf("%d",&c);
			while (c--) {
				scanf("%d",&aux);
				chaves[i].set(aux,1);
			}
		}

		total = 0;
		menor = INF;
		vi a;
		dp(0,a,total);

		if (menor == INF) printf("Desastre!\n");
		else printf("%d\n",menor);
	}
	return 0;
}
