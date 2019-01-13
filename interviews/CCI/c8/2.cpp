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

void func(int** maze) {
	printf("Número de linhas: %d\n",(int)(sizeof(maze)));
	printf("Número de colunas: %d\n",(int)(sizeof(maze[0])));
}

int main() {
	int ** grid;

	grid = new int*[10];
	for (int i = 0; i < 10; i++)
		grid[i] = new int[10];
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			grid[i][j] = i*10+j;
			printf("%2d ",grid[i][j]);
		}
		printf("\n");
	}
	func(grid);

	return 0;
}
