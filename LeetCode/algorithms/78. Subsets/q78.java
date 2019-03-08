class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> l = new ArrayList<>();
        
        solve(0,nums,l,ans);
        
        return ans;
    }
    
    private void solve(int i, int[] nums, List<Integer> l, List<List<Integer>> ans) {
        if (i == nums.length) {
            addToAns(l,ans);
            return;
        }
        
        solve(i+1,nums,l,ans);
        l.add(nums[i]);
        solve(i+1,nums,l,ans);
        l.remove(l.size()-1);
    }
    
    private void addToAns(List<Integer> l, List<List<Integer>> ans) {
        List<Integer> aux = new ArrayList<>(l.size());
        
        aux.addAll(l);
        ans.add(aux);
    }
}