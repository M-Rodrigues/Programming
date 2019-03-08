class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        int i = 0, j = 0, n = 0, index = 0;
        
        while (i < nums1.length || j < nums2.length) {
            if (i == nums1.length) {
                j++;
            } else if (j == nums2.length) {
                i++;
            } else if (nums1[i] == nums2[j]) {
                n++; i++; j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        
        i = 0; j = 0;
        int[] ans = new int[n];
        
        while (i < nums1.length || j < nums2.length) {
            if (i == nums1.length) {
                j++;
            } else if (j == nums2.length) {
                i++;
            } else if (nums1[i] == nums2[j]) {
                ans[index] = nums1[i]; i++; j++; index++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
}