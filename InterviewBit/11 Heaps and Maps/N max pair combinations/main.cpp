typedef pair<int,pair<int,int>> piii;

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    priority_queue<piii> pq; 
    set<pair<int,int>> p;
    
    int N = (int)A.size();
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    pq.push({A[0]+B[0],{0,0}});
    while (ans.size() < N) {
        piii cur = pq.top(); pq.pop();
        int sum = cur.first;
        int i = cur.second.first;
        int j = cur.second.second;
    
        ans.push_back(sum);

        if (p.count({i,j+1}) == 0) {
            pq.push({A[i]+B[j+1],{i,j+1}});
            p.insert({i,j+1});
        }
        if (p.count({i+1,j}) == 0) {
            pq.push({A[i+1]+B[j],{i+1,j}});
            p.insert({i+1,j});
        }
    }
    
    return ans;  
}

