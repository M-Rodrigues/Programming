class Solution {
    public int maxProfit(int[] prices) {
        int mn = Integer.MAX_VALUE;
        int mx = 0;
        int ans = 0;
        
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < mn) {
                if (mx - mn > ans) ans = mx - mn;
                
                mn = prices[i];
                mx = mn; 
            }
            
            if (prices[i] > mx) mx = prices[i];
        }
        
        return (mx-mn > ans ? mx-mn : ans);
    }
}