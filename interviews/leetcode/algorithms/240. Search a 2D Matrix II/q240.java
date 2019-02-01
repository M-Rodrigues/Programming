// O(NLog(M))
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (int i = 0; i < matrix.length; i++) {
            if (Arrays.binarySearch(matrix[i], target) >= 0) return true;
        }   
        return false;
    }
}

// O(Plog(Q)) P = min(N,M), Q = max(N,M)
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int N = matrix.length;
        if (N == 0) return false;
        
        int M = matrix[0].length;
        
        for (int i = 0; i < Math.min(N,M); i++) {
            if (target <= matrix[i][M-1] && target >= matrix[i][0])
                if (bsInRow(i, target, matrix) >= 0) return true;
            if (target <= matrix[N-1][i] && target >= matrix[0][i])
                if (bsInCol(i, target, matrix) >= 0) return true;
        }
        
        return false;
    }
    
    private int bsInRow(int i, int val, int arr[][]) {
        return Arrays.binarySearch(arr[i], val);
    }
    
    private int bsInCol(int i, int val, int arr[][]) {
        return bsInCol(i, val, 0, arr.length-1, arr);
    }
    
    private int bsInCol(int i, int val, int l, int r, int[][] arr) {
        if (r >= l) {
            int mid = l + (r-l)/2;
            
            if (arr[mid][i] == val) 
                return mid;
            
            if (arr[mid][i] > val)
                return bsInCol(i,val,l,mid-1,arr);
            
            return bsInCol(i,val,mid+1,r,arr);
        }
        
        return -1;
    }
}

// O(N+M)
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.length <1 || matrix[0].length < 1) return false;
        int row = 0;
        int col = matrix[0].length - 1;
        
        while(row < matrix.length && col >= 0){
            if(target == matrix[row][col]) return true;
            else if(target < matrix[row][col]) col --;
            else if(target > matrix[row][col]) row ++;
        }  
        
        return false;
    }
}