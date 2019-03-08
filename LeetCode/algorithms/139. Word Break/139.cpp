#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < s.size(); i++) {
            if (search(s.substr(0,i+1), wordDict)) {
                if (solve(s.substr(i+1,s.size()-i-1), wordDict)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool solve(string s, vector<string>& dict) {
        if (s == "") return true;
        
        for (int i = 0; i < s.size(); i++) {
            if (search(s.substr(0,i+1), dict))
                if (solve(s.substr(i+1,s.size()-i-1), dict)) {
                    return true;
                }
        }
        return false;
    }
    
    bool search(string s, vector<string>& dict) {
        for (string ss : dict) if (ss == s) return true;
        return false;
    } 
};

int main() {
    Solution q;

    string s = "aaaaaaa";
    vector<string> dict = {"aaaa","aaa"};

    cout << q.wordBreak(s, dict) << endl;

    return 0;
}