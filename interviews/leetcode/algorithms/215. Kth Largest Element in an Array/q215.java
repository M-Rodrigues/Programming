class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length-k];
    }
}

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int x : nums) pq.add(-x);
        
        int ans = 0;
        while (k > 0) {
            ans = pq.poll();
            k--;
        }
        
        return -ans;
    }
}