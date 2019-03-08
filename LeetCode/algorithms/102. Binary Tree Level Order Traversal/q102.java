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
    public List<List<Integer>> levelOrder(TreeNode root) {
        ArrayList<List<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> l = new ArrayList<>();
        
        buildList(root,0,ans);
        
        return ans;
    }
    
    private void buildList(TreeNode node, int level, ArrayList<List<Integer>> ans) {
        if (node == null) return;
        
        List<Integer> l;
        
        if (ans.size() <= level) {
            l = new ArrayList<Integer>();
            l.add(node.val);
            ans.add(l);
        } else {
            l = ans.get(level);
            l.add(node.val);
            ans.remove(level);
            ans.add(level, l);
        }
        
        buildList(node.left, level+1, ans);
        buildList(node.right, level+1, ans);
    }
}