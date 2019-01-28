class Solution {
    public boolean isValidSudoku(char[][] board) {
        int nums1 = 0, nums2 = 0, nums3 = 0;
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                char c1 = board[i][j];
                char c2 = board[j][i];
                char c3 = board[3*(i / 3)+j/3][j%3+(i%3)*3];
                
                if (c1 != '.' ) {
                    if (getBit(getNum(c1), nums1) == 1) return false;
                    nums1 = setBit(getNum(c1), nums1);
                }
                
                if (c2 != '.') {
                    if (getBit(getNum(c2), nums2) == 1) return false;
                    nums2 = setBit(getNum(c2), nums2);
                }
                        
                if (c3 != '.') {
                    if (getBit(getNum(c3), nums3) == 1) return false;
                    nums3 = setBit(getNum(c3), nums3);
                }
            }
            
            nums1 = 0;
            nums2 = 0;
            nums3 = 0;
        }
        
        return true;  
    }
    
    private int getBit(int i, int n) {
        return (n >> (i-1)) & 1;
    }
    
    private int setBit(int i, int n) {
        return n | (1<<(i-1));
    }
    
    private int getNum(char c) {
        return ((int) c) - ((int) '0');
    }
}