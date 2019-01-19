class Solution {
    List<List<Integer>> ans;
    
    private void addToAnswer(int[] arr) {
        ArrayList<Integer> l = new ArrayList<>(arr.length);
        
        for (int x : arr) l.add(x);
        ans.add(l);
        l = null;
    }
    
    private void swap(int[] arr, int i, int j) {
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    }
    
    private void permute(int[] arr, int index) {
        if (index == arr.length) {
            addToAnswer(arr);
            return;
        }
        
        for (int i = index; i < arr.length; i++) {
            swap(arr,i,index);
            permute(arr,index+1);
            swap(arr,i,index);
        }
        
    }
    
    public List<List<Integer>> permute(int[] nums) {
        ans = new ArrayList<List<Integer>>();
        permute(nums, 0);
        return ans;
    }
}