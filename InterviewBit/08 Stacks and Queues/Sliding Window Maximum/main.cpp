vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    deque<pair<int,int>> q;
    
    for (int i = 0; i < A.size(); i++) {
        /* remove value outside of sliding window */
        if (!q.empty() and q.back().second < i-B+1)
            q.pop_back();
        
        /* keeping the order in the deque */
        while (!q.empty() and q.front().first < A[i])
            q.pop_front();
        q.push_front({A[i],i});
        
        /* get max value */
        if (i >= B-1) ans.push_back(q.back().first);
    }
    
    /* case where B > length of vector */
    if (ans.size() == 0) ans.push_back(q.back().first);

    return ans;
    
}
