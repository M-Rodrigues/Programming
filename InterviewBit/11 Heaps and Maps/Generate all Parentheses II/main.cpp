void build(int n, int op, int cp, string &cur, vector<string> &ans) {
    if (op == n and cp == n) {
        ans.push_back(cur);
        return;
    }
    // if (op > n or cp > n) return;
    // if (cp > op) return;
    
    if (op < n) {
        cur.push_back('(');
        build(n,op+1,cp,cur,ans);
        cur.pop_back();
    }
    
    if (cp < op) {
        cur.push_back(')');
        build(n,op,cp+1,cur,ans);
        cur.pop_back();
    }
}
 
 
vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    string cur = "";
 
    build(A,0,0,cur,ans);
 
    return ans;
}