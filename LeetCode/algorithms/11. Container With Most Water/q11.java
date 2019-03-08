// Time: O(n^2)
class Solution {
    public int maxArea(int[] height) {
        int result = 0;
        
        for (int i = 0; i < height.length; i++) {
            for (int j = i+1; j < height.length; j++) {
                int curr = Math.min(height[i], height[j])*(j-i);
                
                if (curr > result) result = curr;
            }
        }
        
        return result;
    }
}

// Time: O(n)
class Solution {
    public int maxArea(int[] height) {
        int l = 0, r = height.length-1;
        int area = 0;
        
        while (l < r) {
            int aux = Math.min(height[l],height[r])*(r-l);
            if (aux > area) area = aux;
            
            if (height[r] > height[l]) l++;
            else r--;
        }
        
        return area;
    }
}