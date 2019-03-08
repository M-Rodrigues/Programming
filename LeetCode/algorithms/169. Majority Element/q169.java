class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        
        if (nums.length == 1) return nums[0];
        
        for (int x : nums) {
            if (map.containsKey(x)) {
                int freq = map.get(x);
                freq++;
                if (freq > nums.length/2) return x;
                map.replace(x,freq);
            } else {
                map.put(x,1);
            }
        }
        
        return 0;
    }
}