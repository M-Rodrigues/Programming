bool smaller(const vector<int> &s1, const vector<int> &s2) {
    return s2.size() == 0 ? true :
        (s1[0] < s2[0]) or
        (s1[0] == s2[0] and s1[1] < s2[1]) or
        (s1[0] == s2[0] and s1[1] == s2[1] and s1[2] < s2[2]) or
        (s1[0] == s2[0] and s1[1] == s2[1] and s1[2] == s2[2] and s1[3] < s2[3]);
}

vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int, pair<int,int>> m;
    vector<int> ans;
    
    int a1, b1, c1, d1, sum;
    for (int i = 0; i < A.size(); i++) {
        for (int j = i+1; j < A.size(); j++) {
            sum = A[i] + A[j];
            
            if (m.count(sum) == 0) {
                m[sum] = {i,j};
            } else {
                a1 = m[sum].first; 
                b1 = m[sum].second;
                c1 = i;
                d1 = j;
                
                if (a1 < c1 and b1 != d1 and b1 != c1 ) {
                    vector<int> aux({a1,b1,c1,d1});
                    if (smaller(aux,ans))
                        ans = aux;
                }
            }
        }
    }
    
    return ans;
}
