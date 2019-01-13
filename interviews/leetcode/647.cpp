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

class Solution {
public:
    int countPalindromes(string s) {
		int n = s.length(), count = 0;
        for (int center = 0; center <= 2*n-1; ++center) {
			db(count);
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right < N && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        return count;
	}
private:
	
};

int main() {

	Solution sol;

	string s;
	
	s = "asasa";
	cout << sol.countPalindromes(s) << endl;

	return 0;
}
