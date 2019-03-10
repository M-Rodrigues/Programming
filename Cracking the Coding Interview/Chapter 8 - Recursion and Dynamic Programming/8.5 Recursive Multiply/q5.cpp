#include<bits/stdc++.h>
using namespace std;

int RecursiveMultiply(int a, int b) {
	if (b == 0) return 0;
	if (b == 1) return a;

	if (b%2 == 1) return a+RecursiveMultiply(a+a, b>>1);
	return RecursiveMultiply(a+a,b>>1);
}

int main() {
	cout << RecursiveMultiply(0, 3) << endl;
	return 0;
}
