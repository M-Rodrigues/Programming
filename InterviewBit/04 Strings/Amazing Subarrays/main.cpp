int Solution::solve(string A) {
    int ans = 0;
    set<char> vowel;
    
    vowel.insert('a');
    vowel.insert('e');
    vowel.insert('i');
    vowel.insert('o');
    vowel.insert('u');
    vowel.insert('A');
    vowel.insert('E');
    vowel.insert('I');
    vowel.insert('O');
    vowel.insert('U');
    
    for (int i = 0; i < A.size(); i++)
        if (vowel.count(A[i])>0)
            ans = (ans + ((int)A.size() - i)) % 10003;
    return ans;
}
