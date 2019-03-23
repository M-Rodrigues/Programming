vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> nums;
    vector<int> ans;
    
    for (int i = 0; i < A.size(); i++) {
        // remover de nums o numero q acabou de sair da janela
        if (i-B >= 0) {
            int x = A[i-B];
            nums[x]--;
            if (nums[x] == 0) nums.erase(x);
        }
        
        // adicionar em nums o elemento q acabou de entrar na janela
        nums[A[i]]++;
        
        // atualizar a respostas
        if (i >= B-1) ans.push_back(nums.size());
    }
    
    return ans;
}
