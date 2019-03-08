// Brute Force
class Solution {
    public int uniquePaths(int m, int n) {
        return binomial(n-1+m-1,n-1);   
    }
    
    private int binomial(int n, int m) {
        if (m == 0 || n == m) return 1;
        return binomial(n-1, m) + binomial(n-1, m-1);
    }   
    
}

// DP
class Solution {
    public int uniquePaths(int m, int n) {
        int mt[][] = new int[n+m-1][n+m-1];
        
        for (int i = 0; i < n+m-1; i++)
            for (int j = 0; j < n+m-1; j++)
                mt[i][j] = -1;
        
        return dp(n+m-2, n-1, mt);
    }
    
    private int dp(int n, int m, int[][] mt) {
        if (mt[n][m] != -1) return mt[n][m];
        
        if (n == m) {
            mt[n][m] = 1;
            return 1;
        }
        
        if (m == 0) {
            mt[n][m] = 1;
            return 1;
        }
        
        mt[n][m] = dp(n-1, m, mt) + dp(n-1, m-1, mt);
        
        return mt[n][m];
    }
}

// O(n)
class Solution {
    public int uniquePaths(int m, int n) {
        int nn = n+m-2;
        int mm = n-1;
        
        return bino(nn,mm).intValue();
    }
    
    private Long bino(int nn, int mm) {
        if (mm == 0) return 1L;
        
        return bino(nn-1, mm-1)*nn/mm;
    }   
}
