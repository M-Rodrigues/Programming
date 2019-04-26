int maxArea(vector<int>& hist) {
    int ans = 0;
    stack<int> id;
    
    hist.push_back(0);
    
    for (int i = 0; i < hist.size(); i++) {
        if (id.empty() or hist[i] >= hist[id.top()]) {
            id.push(i);
        } else {
            while (!id.empty() and hist[i] < hist[id.top()]) {
                int tp = id.top();
                id.pop();

                ans = max(ans, hist[tp] * (id.empty() ? i : i-id.top()-1));
            }
            id.push(i);
        }
    }
    
    hist.pop_back();
    return ans;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int ans = 0;
    vector<int> hist(A[0].size());
    
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (i == 0) {
                hist[j] = A[i][j];
            } else {
                if (A[i][j] == 1 and A[i-1][j] == 1)
                    hist[j]++;
                else if (A[i-1][j] == 0) {
                    hist[j] = A[i][j];
                } else {
                    hist[j] = 0;
                }
            }
        }
        
        ans = max(ans, maxArea(hist));
    }
    return ans;
}


