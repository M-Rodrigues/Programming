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
const int N = 4e+5;

int cmp[N];
vector<int> p;

void primes() {
    for (ll i = 2; i*i <= N; i++) if(cmp[i] == 0) {
        for (ll j = i*i ; j < N; j+=i) cmp[j] = 1; 
    }
    for (ll i = 2; i < N; i++) if(cmp[i] == 0) p.push_back(i);
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int fexp(int a, int b){
    int res=1;
    while(b>0){
        if(b%2==1) res*=a;
        a*=a;
        b/=2;
    }
    return res;
}

int main() {
	primes();

	// db(p.size());


	int n;
	scanf("%d",&n);
	while (n--) {
		ll a, b;
		scanf("%lld%lld",&a,&b);
		
		ll crt = llround(pow(a*b, 1.0/3));

		
		// ll prod = a*b;
		// int i = 0;
		// bool isCube = true;
		// ll crt = 1;

		// while (prod != 1) {
		// 	ll q = 0;
		// 	ll m = p[i];
		// 	while (prod%m == 0) {
		// 		q++;
		// 		prod /= m;
		// 	}


		// 	if (q%3 != 0) { isCube = false; break; }
		// 	else if (q>0) crt*=fexp(m,q/3);

		// 	i++;
		// 	if (i == p.size()) break;
		// 	if (p[i] > prod) break;
		// }

		// if (!isCube) printf("No\n");
		// else if (crt == 1 and a == b and a == 1) printf("Yes\n");
		// else printf("%s\n",(isCube and a%crt == 0 and b%crt == 0)?"Yes":"No");

		printf("%s\n",(a%crt == 0 and b%crt == 0 and a*b == crt*crt*crt)?"Yes":"No");
	
	}
	return 0;
}
