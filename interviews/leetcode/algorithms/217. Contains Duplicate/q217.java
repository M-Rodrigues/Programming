class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) return true;
        }
        return false;
    }
}

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> s = new HashSet<>();
        
        for (int i = 0; i < nums.length; i++) {
            if (s.contains(nums[i])) return true;
            
            s.add(nums[i]);
        }
        return false;
    }
}