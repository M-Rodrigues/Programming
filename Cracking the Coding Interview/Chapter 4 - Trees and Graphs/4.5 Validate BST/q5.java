import java.util.ArrayList;
import java.util.LinkedList;

public class q5 {
    public static void main(String[] args) {
        BinaryTree t = buildBST();

        System.out.println(isBST(t));
        
        TreeNode n1 = new TreeNode();
        n1.data = 10;
        
        t.root.dir.dir.dir.dir = n1;
        
        System.out.println(isBST(t));
    }

    public static boolean isBST(BinaryTree tree) {
        ArrayList<TreeNode> arr = new ArrayList<TreeNode>();
        inOrder(tree.root, arr);
        return isOrdered(arr);
    }

    public static void inOrder(TreeNode node, ArrayList<TreeNode> arr) {
        if (node == null) return;

        inOrder(node.esq, arr);
        arr.add(node);
        inOrder(node.dir, arr);
    }
    
    public static boolean isOrdered(ArrayList<TreeNode> arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr.get(i).data < arr.get(i-1).data) return false;
        }
        return true;
    }

    // Para construir uma arvore binário para testar exercícios
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