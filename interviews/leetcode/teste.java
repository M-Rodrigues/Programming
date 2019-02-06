import java.util.*;

public class teste {
    public static void main(String[] args) {
        int[][] mtx = {
            {3,3,14,2,17,12,5}
        };

        System.out.println(longestIncreasingPath(mtx));
    }

    public static int longestIncreasingPath(int[][] matrix) {
        // memozation matrix
        int[][] memo = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < memo.length; i++) Arrays.fill(memo[i], -1);
        
        // calculate best solution for each cell
        int ans = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                ans = Math.max(ans, dp(i, j, matrix, memo));
            }
        }



        for (int[] r : memo) {
            for (int x : r) {
                System.out.print(x + " ");
            }
            System.out.print("\n");
        }

        
        return ans;        
    }
    
    private static int dp(int i, int j, int[][] m, int[][] memo) {
        if (!inside(i, j, m)) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        
        int[] x = {1, 0, -1, 0};
        int[] y = {0, 1, 0, -1};
        
        int best = -1;
        for (int k = 0; k < 4; k++) {
            int ii = i + y[k];
            int jj = j + x[k];
            if (inside(ii, jj, m)) {
                if (m[i][j] < m[ii][jj]) {
                    best = Math.max(best, dp(ii, jj, m, memo));
                }
            }
        }
        
        memo[i][j] = ++best;
        return memo[i][j];        
    }
    
    private static boolean inside(int i, int j, int[][] m) {
        if (i < 0 || i >= m.length) return false;
        if (j < 0 || j >= m[i].length) return false;
        return true;
    }
}