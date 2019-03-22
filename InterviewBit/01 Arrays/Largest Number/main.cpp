string Solution::largestNumber(const vector<int> &A) {
    vector<string> ans;
    
    for (int x : A) ans.push_back(to_string(x));
    
    sort(ans.begin(), ans.end(), [](string s1, string s2) {
        if (s1.size() == s2.size()) return s1 >= s2;
        
        int a1 = stoi(s1);
        int a2 = stoi(s2);
        
        return a1+a2*pow(10,(int)s1.size()) <= a2+a1*pow(10,(int)s2.size());
    });
    
    string s = "";
    
    for (string ss : ans) s += (ss == "0" ? "" : ss);
    
    return s == "" ? "0" : s;
}
