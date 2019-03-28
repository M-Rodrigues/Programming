int Solution::majorityElement(const vector<int> &A) {
    map<int,int> freq;
    int N = A.size();
    for (int x : A) {
        int aux = freq[x]++;
        if (aux >= N/2) return x;
    }
}
