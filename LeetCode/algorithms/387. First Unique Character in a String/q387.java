// 79 ms, 47.71%
class Solution {
    public int firstUniqChar(String s) {
        if (s.length() == 0) return -1;
        
        Set<Character> unique = new HashSet<>();    
        Set<Character> dupl = new HashSet<>();    

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (unique.contains(c)) {
                dupl.add(c);
            } else {
                unique.add(c);
            }
        }
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (!dupl.contains(c)) return i;
        }
        
        return -1;        
    }
}