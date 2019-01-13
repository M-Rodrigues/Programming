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

struct point {
	int x, y;

	point(): x(0), y(0) {}
	point(int x, int y): x(x), y(y) {}
};

struct rect {
	point p1, p2;

	rect() { p1.x = p1.y = p2.x = p2.y = 0; }
	rect(point a, point b) { p1 = a; p2 = b; }

	bool has(point p) { return p.x >= p1.x and p.x <= p2.x and p.y >= p1.y and p.y <= p2.y; }
};

int main() {
	int a, b, c, d;
	
	scanf("%d%d%d%d",&a,&b,&c,&d);
	point p1(a,b); 
	point p2(c,d);
	rect r1(p1,p2);



	scanf("%d%d%d%d",&a,&b,&c,&d);
	p1.x = a;
	p1.y = b;
	p2.x = c;
	p2.y = d;
	rect r2(p1,p2);

	printf("%d\n",r1.has(r1.p1) || r1.has(r1.p2) ? 1 : 0);
	
	return 0;
}
