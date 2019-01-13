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

int T, n, l;
int c[N];
vector<pair<double, int>> data;

int main() {
	scanf("%d",&T);
	for (int t = 1; t <= T; t++) {
		data.clear();
		scanf("%d%d",&n,&l);
		int nrd = 0;
		int nru = 0;
		int sum = 0;

		double delta = (double)1/(double)n*100;
		delta -= (int)delta;
		db(delta);

		int num = 0;
		if (delta != 0) {
			num++;
			if (delta < 0.5) num += 0.5/delta;
		}
		db(num);

		int total_inter = 0;
		for (int i = 0; i < l; i++) {
			scanf("%d",&c[i]);
			total_inter += c[i];

			double aux;
			aux = (double)c[i]/(double)n*100;

			int r;
			if (aux - int(aux) > 0.5 + EPS) {
				r = (int) aux + 1;
				nru++;
			} else {
				r = (int) aux;
				nrd++;
			}
			sum += r;

			int resto = (int)((aux - int(aux))/delta);
			data.pb(mp(aux,resto+1));

			printf("%d: %lf -> %d : %d : %d\n",i,data[i].st,r,sum,data[i].nd);
		}

		printf("Faltam %d a serem entrevistadas\n",n-total_inter);
		printf("Pra cima: %d\tPra baix: %d\n",nru,nrd);

		int ans = 0;
		if (num == 0) ans = 100;
		else {

		} 

		printf("Case #%d: %d\n\n",t,ans);
	}
	return 0;
}
