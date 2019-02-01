/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        ArrayList<List<Integer>> ans = new ArrayList<>();
        
        build(ans, root, 0);
        reverse(ans);
        
        return ans;
    }
    
    private void build(ArrayList<List<Integer>> ans, TreeNode node, int level) {
        if (node == null) return;
        
        if (ans.size() == level) {
            ArrayList<Integer> l = new ArrayList<>();
            l.add(node.val);
            ans.add(l);
        } else {
            ans.get(level).add(node.val);    
        }
                
        build(ans, node.left, level+1);
        build(ans, node.right, level+1);
    }
    
    private void reverse(ArrayList<List<Integer>> ans) {
        for (int i = 1; i < ans.size(); i+=2){
            List<Integer> l = ans.get(i);
            
            for (int j = 0; j < l.size()/2; j++) {
                int aux = l.get(j);
                l.set(j, l.get(l.size()-1-j));
                l.set(l.size()-j-1, aux);
            }
        }
    }
    
}