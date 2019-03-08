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
    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> arr = new ArrayList<>();
        inorder(root, arr);
        return arr;
    }
    
    private void inorder(TreeNode node, ArrayList<Integer> arr) {
        if (node == null) return;
        
        inorder(node.left, arr);
        arr.add(node.val);
        inorder(node.right, arr);
    }
}