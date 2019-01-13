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


format long;
syms t y;
f(t,y)=y*y*t*exp(t*t);
n=7;
t=1:n+1;
y=1:n+1;
t(1)=0;
y(1)=0.8;
h=0.1;
for i=1:n
	yEuler=y(i)+h*f(t(i),y(i));
	y(i+1)=y(i)+h*( f(t(i),y(i)) + f(t(i)+h,yEuler) )/2;
	t(i+1)=t(i)+h;
	disp([t(i+1),y(i+1)])
end





class Solution {
public:
	int nextGreaterElement(int n) {
		int num[32], tam = 0;
		memset(num, 0, sizeof(num));
		
		while (n != 0) {
			num[tam] = n%10; 
			n /= 10;
			tam++;
		}
		int prev = buildNumber(num,tam);
		
		for (int i = 0; i < tam - 1; i++) {
			if (num[i] > num[i+1]) {
				swap(num[i],num[i+1]);
				if (i > 0) {
					while (num[i] > num[i-1]) {
						swap(num[i], num[i-1]);
						i--;
						if (i == 0) break;
					}
				}
				break;
			}
		}		
		int ans = buildNumber(num,tam);
		
		return (prev == ans) ? -1 : ans;
	}
private:
	int buildNumber(int num[], int tam) {
		int n = 0;
		for (int i = 0; i < tam; i++)
			n += num[i]*(pow(10,i));
		return n;
	}
};

int main() {
	Solution sol;
	cout << sol.nextGreaterElement(12) << "(ans: 21)" << endl;
	cout << sol.nextGreaterElement(21) << "(ans: -1)" << endl;
	cout << sol.nextGreaterElement(123) << "(ans: 132)"<< endl;
	cout << sol.nextGreaterElement(3) << "(ans: -1)" << endl;
	cout << sol.nextGreaterElement(7645438) << "(ans: 7645483)" << endl;
	cout << sol.nextGreaterElement(7431) << "(ans: -1)" << endl;
	cout << sol.nextGreaterElement(230241) << "(ans: 230412)" << endl;
	return 0;
}
