vector<string> split(string &s) {
    string cur = "";
    vector<string> ans;
    
    for (char c : s) {
        if (c == '/') {
            if (cur != "") {
                ans.push_back(cur);
                cur = "";
                continue;
            }
        } else {
            cur.push_back(c);
        }
    }
    
    return ans;
}

string Solution::simplifyPath(string A) {
    if (A == "") return "/";
    if (A[A.size()-1] != '/') A.push_back('/');
    
    vector<string> dirs = split(A);
    stack<string> ans, aux;
    
    for (string s : dirs) {
        // printf("%s\n",s.c_str());
        if (s == "..") {
            if (!ans.empty()) ans.pop();
            continue;
        }
        
        if (s != ".") ans.push(s);
    }
    
    while (!ans.empty()) {
        aux.push(ans.top());
        ans.pop();
    }
    
    string s = "";
    while (!aux.empty()) {
        s += "/" + aux.top();
        aux.pop();
    }
    return s == "" ? "/" : s;
}
