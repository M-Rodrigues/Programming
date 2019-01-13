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
	ld x, y, z;
	
	point(ld x, ld y, ld z): x(x), y(y), z(z) {}

	ld pEsc(point p) { return x*p.x + y*p.y + z*p.z; }

	ld abs() { return sqrt(x*x + y*y + z*z); }

	void print() {
		cout << setprecision(16) << x << " " << y << " " << z << " " << endl;			
	}

	point Rz(ld alfa) {
		vector<ld> a;
		a.pb(x); a.pb(y); a.pb(z);

		ld R[3][3];

		R[0][0] = cos(alfa);
		R[0][1] = -sin(alfa);
		R[0][2] = 0;

		R[1][0] = sin(alfa);
		R[1][1] = cos(alfa);
		R[1][2] = 0;
		
		R[2][0] = 0;
		R[2][1] = 0;
		R[2][2] = 1;

		ld res[3];
		cl(res,0);

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) 
				res[i] += R[i][j]*a[j]; 
		
		return point(res[0], res[1], res[2]);
	}

	point Rx(ld alfa) {
		vector<ld> a;
		a.pb(x); a.pb(y); a.pb(z);

		ld R[3][3];

		R[0][0] = 1;
		R[0][1] = 0;
		R[0][2] = 0;

		R[1][0] = 0;
		R[1][1] = cos(alfa);
		R[1][2] = -sin(alfa);
		
		R[2][0] = 0;
		R[2][1] = sin(alfa);
		R[2][2] = cos(alfa);

		ld res[3];
		cl(res,0);

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) 
				res[i] += R[i][j]*a[j]; 
		
		return point(res[0], res[1], res[2]);
	}

	ld areaInY(point Oy) {
		ld costheta = abs(this->pEsc(Oy))/this->abs()/Oy.abs();
		ld area = this->abs()*2;
		
		return area*costheta;
	}
};

int T, t;
ld A;

point p1(0.5,0,0);
point p2(0,0.5,0);
point p3(0,0,0.5);
point Oy(0,1,0);

ld shadowArea(point &p1, point &p2, point &p3) {
	return p1.areaInY(Oy) + p2.areaInY(Oy) + p3.areaInY(Oy);
};

int main() {
	cin >> T;
	while (T--) {
		t++;
		cin>>A;

		printf("Case #%d:\n",t);
		
		if (A - EPS < 1) {
			p1.print();
			p2.print();
			p3.print();
		} else if (A - EPS < sqrt(2)) {
			ld lo = 0;
			ld hi = PI/4;
			ld md;

			point a1 = p1, a2 = p2, a3 = p3;

			for (int i = 0; i < 1000; i++) {
				md = (lo+hi)/2;

				a1 = p1.Rz(md);
				a2 = p2.Rz(md);
				a3 = p3.Rz(md);

				ld a = shadowArea(a1,a2,a3);

				if (a - EPS < A) lo = md;
				else hi = md;
			}
			
			a1 = p1.Rz(md);
			a2 = p2.Rz(md);
			a3 = p3.Rz(md);

			a1.print();
			a2.print();
			a3.print();

		} else {
			p1 = p1.Rz(PI/4);
			p2 = p2.Rz(PI/4);
			p3 = p3.Rz(PI/4);

			ld lo = 0;
			ld hi = asin(sqrt(2)/sqrt(3));
			ld md;

			point a1 = p1, a2 = p2, a3 = p3;

			for (int i = 0; i < 1000; i++) {
				md = (lo+hi)/2;

				a1 = p1.Rx(md);
				a2 = p2.Rx(md);
				a3 = p3.Rx(md);

				ld a = shadowArea(a1,a2,a3);

				if (a - EPS < A) lo = md;
				else hi = md;
			}
			
			a1 = p1.Rx(md);
			a2 = p2.Rx(md);
			a3 = p3.Rx(md);

			a1.print();
			a2.print();
			a3.print();
		}
	}

	return 0;
}
