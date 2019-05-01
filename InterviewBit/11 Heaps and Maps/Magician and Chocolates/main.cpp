const int mod = 1e9+7;

int Solution::nchoc(int A, vector<int> &B) {
    long long sum = 0;
    priority_queue<int> pq;
    
    for (int x : B) pq.push(x);
    
    while (!pq.empty() and A) {
        int a = pq.top();
        pq.pop();
        
        sum = (sum+a)%mod;
        a /= 2;
        
        if (a != 0) pq.push(a);
        A--;
    }
    
    return sum;
}
