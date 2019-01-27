// Time O(nm)
// Memory O(nm)
class Solution {
    public void gameOfLife(int[][] board) {
        int[][] fut = new int[board.length][board[0].length];
        
        for (int i = 0; i < board.length; i++) {
            for (int j  = 0; j < board[i].length; j++) {
                fut[i][j] = nextState(i,j,board);
            }
        }
        
        for (int i = 0; i < board.length; i++) {
            for (int j  = 0; j < board[i].length; j++) {
                board[i][j] = fut[i][j];
            }
        }
    }
    
    private int nextState(int i, int j, int[][] board) {
        boolean isDead = board[i][j] == 0 ? true : false;
        
        int neig = countNeighbours(i,j,board);
        if (isDead) {
            return neig == 3 ? 1 : 0;
        }
        
        if (neig < 2 || neig > 3) return 0;
        return 1;
    }
    
    private int countNeighbours(int i, int j, int[][] b) {
        int n = 0;
        n += (i > 0 && b[i-1][j] == 1 ? 1 : 0);
        n += (i > 0 && j > 0 && b[i-1][j-1] == 1 ? 1 : 0);
        n += (i > 0 && j+1 < b[0].length && b[i-1][j+1] == 1 ? 1 : 0);
        n += (j > 0 && b[i][j-1] == 1 ? 1 : 0);
        n += (j+1 < b[0].length && b[i][j+1] == 1 ? 1 : 0);
        n += (i+1 < b.length && j > 0 && b[i+1][j-1] == 1 ? 1 : 0);
        n += (i+1 < b.length && b[i+1][j] == 1 ? 1 : 0);
        n += (i+1 < b.length && j+1 < b[0].length && b[i+1][j+1] == 1 ? 1 : 0);
        
        return n;
    }
}