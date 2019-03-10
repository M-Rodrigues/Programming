#include<bits/stdc++.h>
using namespace std;

void PowerSet(int i, vector<int> &aux, vector<vector<int>> &ans, const vector<int> &A) {
	if (i == A.size()) {
		ans.push_back({});
		ans[ans.size()-1] = aux;
		return;
	}

	PowerSet(i+1, aux, ans, A);

	aux.push_back(A[i]);
	PowerSet(i+1, aux, ans, A);
	aux.pop_back();
}

vector<vector<int>> PowerSet(const vector<int> &A) {
	vector<vector<int>> ans;
	vector<int> aux;

	PowerSet(0,aux,ans,A);
	
	return ans;
}



int main() {
	vector<int> A({1,2,3,7,4});
	vector<vector<int>> sets = PowerSet(A);

	for (auto l : sets) {
		for (int x : l) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}
