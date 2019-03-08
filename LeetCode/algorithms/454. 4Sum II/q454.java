class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int count = 0;
        
        Map<Integer, Integer> mp1 = new HashMap<>();
        
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                int x = -A[i] - B[j];
                Integer freq = mp1.get(x);
                if (freq != null) {
                    mp1.replace(x,freq+1);
                } else {
                    mp1.put(x,1);
                }
            }
        }

        for (int i = 0; i < C.length; i++) {
            for (int j = 0; j < D.length; j++) {
                int x = C[i] + D[j];
                Integer freq = mp1.get(x);
                if (freq != null) {
                    count += freq;
                }
            }
        }

        
        return count;
    }
}