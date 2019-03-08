import java.util.ArrayList;
import java.util.Stack;

public class q10 {
    public static void main(String[] args) {
        BinaryTree tree = buildBST();
        
        Stack<TreeNode> st = new Stack<TreeNode>();

        st.add(tree.root);
        while (!st.isEmpty()) {
            TreeNode node = st.pop();

            System.out.print(node.data + ", ");

            if (node.dir != null) st.add(node.dir);
            if (node.esq != null) st.add(node.esq);
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