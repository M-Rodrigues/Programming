class Solution {
    public List<String> letterCombinations(String digits) {
        char[] dig = digits.toCharArray();
        ArrayList<String> ans = new ArrayList<>();
        StringBuilder word = new StringBuilder();
        
        Map<Character, Character> m = new HashMap<>();
        m.put('2', 'a');
        m.put('3', 'd');
        m.put('4', 'g');
        m.put('5', 'j');
        m.put('6', 'm');
        m.put('7', 'p');
        m.put('8', 't');
        m.put('9', 'w');
        
        if (dig.length != 0) build(0, ans, word, dig, m);
        
        return ans;
    }
    
    private void build(int i, ArrayList<String> ans, StringBuilder word, char[] dig, Map<Character, Character> m) {
        if (i == dig.length) {
            ans.add(word.toString()); return;
        }
            
        int len = (dig[i] == '9' || dig[i] == '7' ? 4 : 3);
        
        char c = m.get(dig[i]);
        for (int k = 0; k < len; k++) {
            word.append(c);
            build(i+1, ans, word, dig, m);
            word = word.deleteCharAt(word.length()-1);
            c++;
        }        
    }
}