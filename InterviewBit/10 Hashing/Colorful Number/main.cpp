int Solution::colorful(int A) {
    unordered_set<long long int> p;
    long long int prod;
    
    string s = to_string(A);
    
    for (int i = 0; i < s.size(); i++) {
        prod = 1;
        for (int j = i; j < s.size(); j++) {
            prod *= (s[j]-'0');
            
            if (p.count(prod) > 0) return 0;
            else p.insert(prod);
        }
        
    }
    
    return 1;
}
