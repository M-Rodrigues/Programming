class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return {-1, -1};
        
        int l = lowerBound(nums, 0, nums.size()-1, target);
        int u = upperBound(nums, 0, nums.size()-1, target);
        
        l = nums[l] == target ? l : -1;
        u = nums[u] == target ? u : -1;
        return {l, u};
    }
private:
    int lowerBound(vector<int>&arr, int l, int r, int val) {
        if (l == r) return l;
        
        int mid = (l+r)/2;
        
        if (arr[mid] >= val) return lowerBound(arr, l, mid, val);
        else return lowerBound(arr, mid+1, r, val);
    }
    
    int upperBound(vector<int>&arr, int l, int r, int val) {
        if (l == r) return r;
        
        int mid = (l+r+1)/2;
        
        if (arr[mid] <= val) return upperBound(arr, mid, r, val);
        else return upperBound(arr, l, mid-1, val);
        
        return 0;
    }
};