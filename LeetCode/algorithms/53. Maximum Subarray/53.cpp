class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int ans, cur;
    
    for (int i = 0; i < nums.size(); i++) {
      if (i == 0) {
        cur = ans = nums[i];
        continue;
      }
      
      if (cur < 0) {
        cur = nums[i];
      } else {
        if (cur + nums[i] < 0) {
          cur = nums[i];
        } else {
          cur += nums[i];
        }
      }
      ans = max(ans, cur);
    }
    
    return ans;
  }
};