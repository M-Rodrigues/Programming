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

int A, num_test_cases, i, ii, jj, j, num_tries = 1000, grid[N][N];

int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1, +0};
int dy[] = {+1, -1, +0, +0, -1, +1, +1, -1, +0};

int main() {
  int num_test_cases;
  cin >> num_test_cases;
  for (int a = 0; a < num_test_cases; a++) {
	cin >> A;
	cl(grid, 0);

	i = j = 100;
	int moves = 0;
	for (int b = 0; b < 1000; b++) {
		cout << i << " " << j << endl;
		cin >> ii >> jj;

		if (ii == -1 and jj == -1) break; // deu ruim
		if (ii == 0 and jj == 0) break; // consegui!

		grid[ii][jj] = 1;

		bool ok = true;
		for (int k = 0; k < 9; k++) {
			int xx = i + dx[k];
			int yy = j + dy[k];

			if (grid[xx][yy] == 0) ok = false;
		}

		if (ok and moves < 22) i+=3, moves++;
		else if (ok) i++;
	}

  }
  return 0;
}