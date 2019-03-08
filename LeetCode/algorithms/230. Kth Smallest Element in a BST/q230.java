/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

 // 2ms, 46.21%
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        ArrayList<Integer> arr = new ArrayList<>();
        
        inOrder(root, arr);
        
        return arr.get(k-1);
    }
    
    private void inOrder(TreeNode node, ArrayList<Integer> arr) {
        if (node == null) return;
        
        inOrder(node.left, arr);
        arr.add(node.val);
        inOrder(node.right, arr);
    }
}

class Solution {
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> st = new Stack<>();
        TreeNode curr = root;
        
        st.push(root);
        
        while (!st.isEmpty()) {
            while (curr.left != null) {
                curr = curr.left;
                st.push(curr);
            }
            
            
            curr = st.pop(); 
            k--;
            if (k == 0) return curr.val;
            
            
            if (curr.right != null) {
                curr = curr.right;
                st.push(curr);
            }
        }
        
        return 0;
    }
}