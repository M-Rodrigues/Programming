import java.util.ArrayList;

public class q8 {
    public static void main(String[] args) {
        BinaryTree t = buildBST();
        
        TreeNode lca = LCA(t, 7, 6);

        System.out.println(lca.data);
    }

    public static TreeNode LCA(BinaryTree tree, int n1, int n2) {
        TreeNode a = new TreeNode(); a.data = n1;
        TreeNode b = new TreeNode(); b.data = n2;

        return LCA(tree.root, a, b);
    }

    public static TreeNode LCA(TreeNode n, TreeNode a, TreeNode b) {
        if (n == null) return null;

        TreeNode left = LCA(n.esq,a,b);
        TreeNode right = LCA(n.dir,a,b);

        if (left == null && right == null) {
            return (n.data == a.data || n.data == b.data) ? n : null;
        }
        
        if (left != null && right != null) {
            return n;
        }

        if (left == null) {
            return (n.data == a.data || n.data == b.data) ? n : right;
        } else {
            return (n.data == a.data || n.data == b.data) ? n : left;
        }
    } 
        
    public static BinaryTree buildBST() {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(5);
        arr.add(6);
        arr.add(7);
        arr.add(9);
        arr.add(10);
        arr.add(14);
        arr.add(20);
        arr.add(21);

        BinaryTree tree = new BinaryTree();
        tree.root = build(arr, 0, arr.size()-1);
        return tree;
    }

    public static TreeNode build(ArrayList<Integer> arr, int l, int r) {
        if (l > r) return null;

        int mid = (l + r)/2;
        TreeNode n = new TreeNode();
        
        n.data = arr.get(mid);
        n.esq = build(arr,l,mid-1);
        n.dir = build(arr,mid+1,r);

        return n;
    }
}