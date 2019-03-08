// Two pass array
class Solution {
    public int findPeakElement(int[] nums) {
        int l = nums[0];
        int r = nums[nums.length-1];
        
        for (int i = 0; i < nums.length - 1; i++) {
            nums[i] = nums[i+1] - nums[i];
        }
        
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] >= 0 && nums[i+1] < 0) return i+1;
        }
        
        return (l > r) ? 0 : nums.length-1;
    }
}

// One pass array
class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length-1;
        
        if (n == 1) return nums[0] > nums[1] ? 0 : 1;
        
        for (int i = 1; i < n; i++) {
            if (nums[i-1]<=nums[i] && nums[i+1]<=nums[i]) return i;
        }
        
        return nums[0] > nums[n] ? 0 : n;
    }
}