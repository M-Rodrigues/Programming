import java.util.ArrayList;

public class q2 {
    public static void main(String[] args) {
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

        BinaryTree t = buildBST(arr);

        preOrder(t.root, "");
    }

    public static void preOrder(TreeNode n, String s) {
        if (n == null) return;

        System.out.print(n.data + ", ");
        preOrder(n.esq, s);
        preOrder(n.dir, s);
    }

    public static BinaryTree buildBST(ArrayList<Integer> arr) {
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