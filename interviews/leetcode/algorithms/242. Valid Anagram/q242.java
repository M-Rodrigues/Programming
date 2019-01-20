class Solution {
    public boolean isAnagram(String s, String t) {
        char[] s1 = s.toCharArray();
        char[] s2 = t.toCharArray();
        
        Arrays.sort(s1);
        Arrays.sort(s2);
        
        return Arrays.equals(s1,s2);
    }
}

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        
        Map<Character, Integer> map1 = new HashMap<>();
        Map<Character, Integer> map2 = new HashMap<>();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!map1.containsKey(c)) {
                map1.put(c,1);
            } else {
                map1.replace(c,map1.get(c)+1);
            }
        }
        
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (!map2.containsKey(c)) {
                map2.put(c,1);
            } else {
                map2.replace(c,map2.get(c)+1);
            }
        }
        
        
        for (Map.Entry elem : map1.entrySet()) {
            char c = (char) elem.getKey();
            int freq = (int) elem.getValue();
            
            if (!map2.containsKey(c) || map2.get(c) != freq) return false;
        }
        return true;
    }
}