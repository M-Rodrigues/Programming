bool isPalindrome(string s) {
    for (int i = 0; i < s.size()/2; i++)
        if (s[i] != s[s.size()-i-1]) 
            return false;
    return true;
}

void build(string s, vector<string> &cur, vector<vector<string>> &ans) {
    if (s ==  "") {
        ans.push_back(cur);
        return;
    }
    
    for (int i = 0; i < s.size(); i++) {
        string aux = s.substr(0,i+1);
        if (isPalindrome(aux)) {
            cur.push_back(aux);
            build(s.substr(i+1,s.size()-i-1),cur,ans);
            cur.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> ans;
    vector<string> cur;
    
    build(A, cur, ans);
    return ans;
}
