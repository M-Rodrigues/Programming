class Solution {
    public boolean isHappy(int n) {
        Set<Integer> s = new HashSet<>();
        
        int nn = sumSquares(n);
        s.add(nn);
        while (nn != 1) {
            nn = sumSquares(nn);
            
            if (s.contains(nn)) return false;
            s.add(nn);
        }
        
        return true;
    }
    
    private int sumSquares(int n) {
        if (n == 0) return 0;
        return (n%10)*(n%10) + sumSquares(n/10);
    }
}