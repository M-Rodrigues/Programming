class Solution {
    public int[] plusOne(int[] digits) {
        int numOf9 = 0;
        
        for (int x : digits) if (x == 9) numOf9++;
        
        if (numOf9 == digits.length) {
            int[] ans = new int[numOf9+1];
            
            ans[0] = 1;
            Arrays.fill(ans, 1, ans.length-1, 0);
            
            return ans;
        }
        
        int carry = 1;
        
        int i = digits.length-1;
        while (carry == 1) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                carry = 0;   
            }
            
            i--;
        }
        
        return digits;
    }
    
}