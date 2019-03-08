class Solution {
    int[] x = {0, 1, 0, -1};
    int[] y = {1, 0, -1, 0};
    
    public int numIslands(char[][] grid) {
        int tot = 0;
        for (int i = 0; i < grid.length; i++)
            for (int j = 0; j < grid[i].length; j++)
                if (grid[i][j] == '1') {
                    dfs(i, j, grid); tot++;
                }
        return tot;
    }
    
    private void dfs(int i, int j, char[][] g) {
        if (i < 0 || i >= g.length) return;
        if (j < 0 || j >= g[i].length) return;
        if (g[i][j] == '0') return;
        
        g[i][j] = '0';
        for (int k = 0; k < 4; k++)
            dfs(i+y[k], j+x[k], g);
    }
}