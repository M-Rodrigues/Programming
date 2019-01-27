class Solution {
    public int hammingWeight(int n) {
        int cnt = 0;

        if (n < 0) {
            n = n & ~(1<<31);
            cnt++;
        }

        while (n != 0) {
            cnt += (n & 1);
            n >>= 1;
        }

        return cnt;   
    }
}