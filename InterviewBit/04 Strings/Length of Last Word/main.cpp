int Solution::lengthOfLastWord(const string A) {
    if (A == "") return 0;
    
    int i = A.size()-1;
    while (A[i] == ' ' and i >= 0) i--;
    
    if (i == -1) return 0;
    
    int j = i-1;
    while (j >= 0 and A[j] != ' ') j--;
    
    return i - j;
}
