class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new LinkedList<String>();
        char[] seq = new char[2*n];
        solve(seq,0,0,n,ans);
        return ans;
    }
    
    private void solve(char[] seq, int op, int cp, int n, List<String> ans) {
        if (op == n && cp == n) {
            addToAns(seq, ans);
            return;
        }
        
        int i = op + cp;
        if (op < n) {
            seq[i] = '(';
            solve(seq,op+1,cp,n,ans);
        }
        
        if (cp < op) {
            seq[i] = ')';
            solve(seq,op,cp+1,n,ans);
        }
    }
    
    private void addToAns(char[] seq, List<String> ans) {
        ans.add(String.valueOf(seq));
    }
}