int Solution::lis(const vector<int> &A) {
    vector<int> dp;
    
    for (int x : A) {
        int i = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        if (i == dp.size()) dp.push_back(x);
        dp[i] = min(dp[i], x);
    }
    
    return (int)dp.size();
}