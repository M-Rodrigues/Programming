#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> getFreqs(const string &s) {
	unordered_map<char, int> freq;

	for (char c : s) freq[c]++;

	return freq;
}

void build(string &s, int size, unordered_map<char,int> &freq, vector<string> &ans) {
	if (size == 0) { ans.push_back(s); return; }

	for (auto it : freq) {
		if (it.second > 0) {
			freq[it.first]--;
			s.push_back(it.first);

			build(s,size-1,freq,ans);

			s.pop_back();
			freq[it.first]++;
		}
	}
}

vector<string> perms(string s) {
	vector<string> ans;
	string aux = "";
	unordered_map<char, int> freq = getFreqs(s);

	build(aux, (int)s.size(), freq, ans);

	return ans;
}

int main() {
	string s = "abbcdd";

	vector<string> ans = perms(s);

	for (string ss : ans)
		cout << ss << endl;

	return 0;
}
