class Solution {
    public List<List<Integer>> generate(int numRows) {
        if (numRows < 0) return null;
        
        ArrayList<List<Integer>> ans = new ArrayList<>(numRows);    
        for (int n = 0; n < numRows; n++) {
            ArrayList<Integer> l = new ArrayList<>(n+1);
            for (int m = 0; m <= n; m++) {
                if (n == 0 || m == 0 || m == n) {
                    l.add(1);
                } else {
                    l.add(ans.get(n-1).get(m) + ans.get(n-1).get(m-1));
                }
            }
            ans.add(l);
        }
        
        return ans;
    }
}