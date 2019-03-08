#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        ans.clear(), cur.clear();
        this->s = s;
        
        partition(0, s.size()-1);
        
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> cur;
    string s;

    bool isPalindrome(int L, int R) {
        for (int i = L; i < (L+R+1)/2; i++) if (s[i] != s[R-(i-L)]) return false;
        return true;
    }
    
    void partition(int L, int R) {
        if (L > R) {
            vector<string> valid (cur);
            ans.push_back(valid);
            return;
        }
        for (int i = L; i <= R; i++) {
            if (isPalindrome(L, i)) {          
                cur.push_back(s.substr(L, (i-L)+1)); 
                partition(i+1, R);
                cur.pop_back();
            }
        }
    }
};

int main() {
    Solution q;

    vector<vector<string>> ans(q.partition("aab"));

    cout << ans.size() << endl;

    for (auto v : ans) {
        for (string s : v) {
            printf("%s ",s.c_str());
        }
        printf("\n");
    }
}