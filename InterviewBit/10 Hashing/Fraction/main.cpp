string Solution::fractionToDecimal(int A, int B) {
    string ans = "";
    long long int num = A, den = B;
    
    if ((num < 0) ^ (den < 0) and num != 0) ans = "-";

    if (num < 0) num = -num;
    if (den < 0) den = -den;
    
    
    long long int intpart = num/den;
    num %= den;
    if (num == 0) return ans + to_string(intpart);
    
    
    string s = "";
    unordered_map<int,int> pos;
    
    while (num != 0 and pos.count(num) == 0) {
        int c = 10*num/den;
        
        pos[num] = s.size();
        
        printf("%d -> %d\n",num,pos[num]);
        s.push_back(c+'0');
        
        num = 10*num % den;
    }
    printf("%d -> %d\n",num,pos[num]);
    
    if (num == 0) {
    /* decimal exato */
        return ans + to_string(intpart) + "." + s;
    } else {
    /* decimal periodico */
        int i = pos[A];
        string periodic = s.substr(i,s.size()-i);
        string non      = s.substr(0,i); 
        return ans + to_string(intpart) + "." + non + "(" + periodic + ")";
    }
}
