// Using HashSet
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> sn = new HashSet<>();
        
        for (int x : nums) sn.add(x);
        
        int len = 0;
        for (int i = 0; i < nums.length; i++) {
            if (sn.contains(nums[i])) {
                int n = nums[i] - 1;
                int aux = 1;
                
                while (sn.contains(n)) {
                    sn.remove(n--); aux++;
                }
                
                n = nums[i] + 1;
                while (sn.contains(n)) {
                    sn.remove(n++); aux++;
                }
                
                if (aux > len) len = aux;
            }
        } 
        return len;
    }
}

// Sorting the array
class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        
        Arrays.sort(nums);
        
        int len = 1, aux = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1] + 1) {
                aux++;
            } else if (nums[i] != nums[i-1]){
                aux = 1;
            }
            
            if (aux > len) len = aux;
        }
        
        return len;
    }
}