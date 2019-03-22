void buildMap(vector<vector<char>> &dict) {
    dict.resize(10);
    
    dict[0] = {'0'};
    dict[1] = {'1'};
    dict[2] = {'a','b','c'};
    dict[3] = {'d','e','f'};
    dict[4] = {'g','h','i'};
    dict[5] = {'j','k','l'};
    dict[6] = {'m','n','o'};
    dict[7] = {'p','q','r','s'};
    dict[8] = {'t','u','v'};
    dict[9] = {'w','x','y','z'};
}

void build(int k, string &A, string &s, vector<string> &ans, vector<vector<char>> &dict) {
    if (k == A.size()) { ans.push_back(s); return; }
    
    char num = A[k];
    for (char c : dict[num - '0']) {
        s.push_back(c);
        build(k+1,A,s,ans,dict);
        s.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> ans;
    string s = "";
    vector<vector<char>> numbMap;
    
    buildMap(numbMap);
    build(0,A,s,ans,numbMap);
    
    return ans;
}
