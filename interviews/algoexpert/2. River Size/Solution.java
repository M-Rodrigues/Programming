import java.util.ArrayList;

class Program {
	static int[] x = {1, 0, -1, 0};
	static int[] y = {0, 1, 0, -1};
	
    public static ArrayList<Integer> riverSizes(int[][] matrix) {
        ArrayList<Integer> ans = new ArrayList<>();
            for (int i = 0; i < matrix.length; i++)
                for (int j = 0; j < matrix[i].length; j++)
                    if (matrix[i][j] == 1)
                        ans.add(dfs(i, j, matrix));
            return ans;
    }
	
	private static int dfs(int i, int j, int[][] g) {
		if (i < 0 || i >= g.length) return 0;
		if (j < 0 || j >= g[i].length) return 0;
		if (g[i][j] == 0) return 0;
	
		g[i][j] = 0;
		int val = 0;
		for (int k = 0; k < 4; k++)
            val += dfs(i + y[k], j + x[k], g);
            
		return ++val;
	}
}
