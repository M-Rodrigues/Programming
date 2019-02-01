class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        
        for (int i = 0; i <= n; i++) dp[i] = i;
        int max_s = 0, i = 0;
        
        while ((i+1)*(i+1) <= n) i++;
        
        for (int k = 1; k <= i; k++) {
            for (int j = k*k; j <= n; j++) {
                dp[j] = Math.min(dp[j], 1 + dp[j - k*k]);
            }
        }
        
        return dp[n];
    }
}