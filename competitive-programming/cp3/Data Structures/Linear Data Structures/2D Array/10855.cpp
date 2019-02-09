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

int nn, n;
char b[N][N], s[N][N];

int match(int ii, int jj) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (b[ii+i][jj+j] != s[i][j])
				return 0;
	return 1;
}

int solve() {
	int cnt = 0;
	for (int i = 0; i < nn-n+1; i++)
		for (int j = 0; j < nn-n+1; j++)
			cnt += match(i, j);
	return cnt;
}

void swap (char* a, char* b) {
	char aux = *a;
	*a = *b;
	*b = aux;
}

void rotate() {
	for (int i = 0; i < n; i++) 
		for (int j = i; j < n; j++)
			swap(&s[i][j], &s[j][i]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n/2; j++)
			swap(&s[i][j], &s[i][n-j-1]);
}

int main() {
	while (cin >> nn >> n, n+nn) {
		for (int i = 0; i < nn; i++)
			scanf("%s",b[i]);
		for (int i = 0; i < n; i++)
			scanf("%s",s[i]);
		for (int k = 0; k < 4; k++)
			printf("%d%c",solve(),(k == 3 ? '\n' : ' ')), rotate();
	}
	return 0;
}
