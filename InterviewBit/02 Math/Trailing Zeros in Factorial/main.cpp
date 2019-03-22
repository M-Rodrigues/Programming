int Solution::trailingZeroes(int A) {
    int ans = 1;
    for (int i = 5; i <= A; i*=5) {
        ans *= A/i;
    }
    return ans;
}
