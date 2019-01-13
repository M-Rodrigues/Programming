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
	int memo[1000][1000];
    string longestPalindrome(string s) {
		int n = s.size();

		memset(memo, -1, sizeof(memo));
		
		int i_sol = 0, j_sol = 0, len = 0, max_len = 0;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				if(isPalindrome(i,j,s) == 1)
					if(j - i + 1 > max_len) 
						max_len = j - i + 1, i_sol = i, j_sol = j;
	
		return buildString(s,i_sol,j_sol);
	}
private:
	int isPalindrome(int i, int j, string &s) {
		if (memo[i][j] != -1) return memo[i][j];
		if (i == j) return memo[i][j] = 1;
		if (i+1 == j) return memo[i][j] = s[i] == s[j];

		if (s[i] == s[j]) return memo[i][j] = isPalindrome(i+1,j-1,s);
		return memo[i][j] = 0;
	}

	string buildString(string &s, int i, int j) {
		string ans = "";
		for (; i <= j; i++) ans += s[i];
		return ans;
	}
};

int main() {

	Solution sol;

	string s;
	
	s = "asdaasdasdasd";
	cout << sol.longestPalindrome(s) << endl;

	return 0;
}
