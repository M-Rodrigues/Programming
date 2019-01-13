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

string s;

int main() {
    int n;
    scanf("%d", &n);
	
	int moves = 0;
    int atual = 1;
	
	stack<int> st;
	
	n *= 2;
	while (n--) {
        cin >> s;
        if (s[0] == 'a') {
            int x;
            scanf("%d", &x);
            st.push(x);
        }
        else {
            atual++;
            if (st.empty()) continue;
            if (st.top() == atual - 1) {
                st.pop();
            }
            else {
                moves++;
                while (!st.empty()) st.pop();
            }
        }
    }
    printf("%d\n", moves);

	return 0;
}
