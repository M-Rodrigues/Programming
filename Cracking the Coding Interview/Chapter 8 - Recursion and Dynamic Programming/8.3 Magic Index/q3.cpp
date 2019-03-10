#include<bits/stdc++.h>
using namespace std;

int magicIndex(int start, int end, const vector<int> &A) {
	if (start > end) return -1;

	int mid = (start+end)/2;

	if (A[mid] == mid) return mid;
	if (A[mid] > mid) return magicIndex(start,mid-1,A);
	return magicIndex(mid+1,end,A);
}

int magicIndex(const vector<int> &A) {
	return magicIndex(0,A.size()-1,A);
}

int main() {
	vector<int> a({-2,0,2,5,6,10});

	cout << magicIndex(a) << endl;

	return 0;
}
