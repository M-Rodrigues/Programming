class Solution {
    public int titleToNumber(String s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            int val = getVal(s.charAt(i));
            num += (val * Math.pow(26,s.length() - i - 1));
            
        }
        return num;
    }
    
    private int getVal(char c) {
        return ((int) c ) - ((int) 'A') + 1;
    }
}