class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<pair<int,int>> q;
    
    if (k == 0 or nums.size() == 0) return ans;
    
    for (int i = 0; i < nums.size(); i++) {
      /* remove value outside of sliding window */
      if (!q.empty() and q.back().second < i-k+1)
          q.pop_back();

      /* keeping the order in the deque */
      while (!q.empty() and q.front().first < nums[i])
          q.pop_front();
      q.push_front({nums[i],i});

      /* get max value */
      if (i >= k-1) ans.push_back(q.back().first);
    }

    /* case where B > length of vector */
    if (ans.size() == 0) ans.push_back(q.back().first);

    return ans;
  }
};