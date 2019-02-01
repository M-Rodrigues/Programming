class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        char[] ss = s.toCharArray();
        
        for (int i = 0; i < ss.length; i++) {
            char c = ss[i];
            
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                
                char cc = st.pop();
                
                if (cc == '(' && c == ')' ||
                    cc == '[' && c == ']' ||
                    cc == '{' && c == '}') {} 
                else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
}