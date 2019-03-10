#include<bits/stdc++.h>
using namespace std;

void build(string &s, int op, int cl, int n, vector<string> &ans) {
	if (cl == n) { ans.push_back(s); return; }

	if (op < n) {
		s.push_back('(');
		build(s,op+1,cl,n,ans);
		s.pop_back();
	}

	if(cl < op) {
		s.push_back(')');
		build(s,op,cl+1,n,ans);
		s.pop_back();
	}
}

vector<string> parens(int n) {
	vector<string> ans;
	string aux = "";

	build(aux,0,0,n,ans);

	return ans;
}

int main() {
	int n; cin >> n;

	vector<string> ans = parens(n);

	for (string s : ans)
		cout << s << endl;

	return 0;
}
