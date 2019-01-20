// 45 ms, 32.19%
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                pq.add(matrix[i][j]);
            }
        }
        
        while (k > 1) {
            pq.poll();
            k--;
        }
        return pq.poll();
    }
}


// 356 ms, 0.92%
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        
        ArrayList<Integer> ans = new ArrayList<>(n);
        
        for (int x : matrix[0]) ans.add(x);
        
        for (int i = 1; i < n; i++) {
            ans = merge(ans, matrix[i]);
        }
        
        return ans.get(k-1);
    }
    
    private ArrayList<Integer> merge(ArrayList<Integer> arr1, int[] arr2) {
        ArrayList<Integer> ans = new ArrayList<Integer>(arr1.size() + arr2.length);
        
        int i = 0, j = 0;
        
        while (i < arr1.size() || j < arr2.length) {
            if (i == arr1.size()) {
                ans.add(arr2[j]); j++;
            } else if (j == arr2.length) {
                ans.add(arr1.get(i)); i++;
            } else {
                int a = arr1.get(i);
                int b = arr2[j];
                
                if (a < b) {
                    ans.add(a); i++;
                } else {
                    ans.add(b); j++;
                }
            }
        }
        
        return ans;
    }
}