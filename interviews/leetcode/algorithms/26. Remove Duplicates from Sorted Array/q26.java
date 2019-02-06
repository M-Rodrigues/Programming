class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length < 1) return 0;
        int tail = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[tail-1]) {
                int aux = nums[i];
                nums[i] = nums[tail];
                nums[tail] = aux;
                
                tail++;
            }
        }
        return tail;        
    }
}