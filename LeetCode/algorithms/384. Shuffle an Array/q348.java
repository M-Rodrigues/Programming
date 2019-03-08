// 175 ms, 99,48%
class Solution {
    int[] arr;
    
    public Solution(int[] nums) {
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        int[] shuf = new int[arr.length];

        ArrayList<Integer> aux = new ArrayList<Integer>(arr.length);
        for (int x : arr) aux.add(x);
        
        Random gen = new Random();
        
        for (int i = 0; i < arr.length; i++) {
            int index = gen.nextInt(aux.size());
            shuf[i] = aux.get(index);
            aux.remove(index);
        }
        
        return shuf;
    }
}