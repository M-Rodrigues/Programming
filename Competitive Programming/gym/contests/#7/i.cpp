#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e4+5;

int bit[N];

void add(int x, int v) {
	while (x < N) {
		bit[x] += v;
		x += x & (-x);
	}
}

ll query(int x) {
	ll ans = 0;
	while (x > 0) {
		ans += bit[x];
		x -= x & (-x);
	}	
}

int main() {
	

	return 0;
}
