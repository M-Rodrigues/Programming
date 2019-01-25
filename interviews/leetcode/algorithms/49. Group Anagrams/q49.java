// 1%
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        
        for (String s : strs) {
            boolean chk = false;
            for (List<String> l : ans) {
                if (isAnagram(l.get(0),s)) {
                    l.add(s);
                    chk = true;
                }
            }
                
            if (!chk) {
                ArrayList<String> l = new ArrayList<>();
                l.add(s);
                ans.add(l);
            }
        }
        
        return ans;
    }
    
    private boolean isAnagram(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        
        char[] arr1 = s1.toCharArray();
        char[] arr2 = s2.toCharArray();
        
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        
        return Arrays.equals(arr1, arr2);
    }
}
