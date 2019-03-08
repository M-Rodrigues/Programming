class Solution {
    public void sortColors(int[] nums) {
        int l = 0, r = nums.length-1, i = 0;
        
        if (nums.length <= 1) return;
        
        while (l < nums.length && nums[l] == 0) l++;
        while (r >= 0 && nums[r] == 2) r--;
        
        i = l;
        while (i <= r) {
            if (nums[i] == 2) {
                swap(i, r, nums); 
                
                while (r >= 0 && nums[r] == 2) r--;
            }            
            
            if (i >= l && nums[i] == 0) {
                swap(l, i, nums);
                
                while (l < nums.length && nums[l] == 0) l++;        
            }
            
            i++;
        }
    }
    
    private void swap(int i, int j, int[] arr) {
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    }
}