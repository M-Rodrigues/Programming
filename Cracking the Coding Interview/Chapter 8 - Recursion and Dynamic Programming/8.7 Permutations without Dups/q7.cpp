#include<bits/stdc++.h>
using namespace std;

vector<string> permute(string s) {
	if (s.size() == 1) {
		vector<string> ans(1);
		ans[0].push_back(s[0]);
		return ans;
	}

	vector<string> aux = permute(s.substr(1,s.size()-1));
	vector<string> ans;

	for (string ss : aux) {
		for (int i = 0; i < ss.size(); i++) {
			string as = ss.substr(0,i);
			as.push_back(s[0]);
			as += ss.substr(i,ss.size()-i);
			
			ans.push_back(as);
		}

		ss.push_back(s[0]);
		ans.push_back(ss);
	}

	aux.clear();
	return ans;
}

int main() {
	string s = "abcde";

	vector<string> ans = permute(s);

	for (string s : ans)
		cout << s << endl;

	return 0;
}
