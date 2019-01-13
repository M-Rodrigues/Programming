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

int faces[6][3][3];
char ordem[6] = {'F', 'B', 'U', 'D', 'L', 'R'};
string moves;

int id (char c) { for (int i = 0; i < 6; i++) if (ordem[i] == c) return i; }

bool check() {
	for (int k = 0; k < 6; k++) 
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (faces[k][i][j] != i*3+j)
					return false;
	return true;
}

int main() {
	for (int k = 0; k < 6; k++) 
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				faces[k][i][j] = i*3+j;

	cout << check() << endl;

	while (cin >> moves) {
		cout << moves << endl;

		for (int i = 0; i < moves.size(); i++)
			if (moves[i] <= 'z' and moves[i] >= 'a') moves[i] += 'A' - 'a';

		do {

		} while (!check());
	}


	

	return 0;
}
