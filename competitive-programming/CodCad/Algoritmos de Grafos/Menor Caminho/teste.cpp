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

int memo[N][N];
int a[N] = {1,3,9,4,7,6};
int b[N] = {1,4,6};
int l[N];


int lis(int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(l, l+j, a[i]) - l;
        l[pos] = a[j]; j = max(j, pos+1);
    }
    return j;
}
  
int main() {
  cl(memo, -1);
  cl(l, 0);
  
  printf("%d\n",lis(6));

  

  return 0;
}
