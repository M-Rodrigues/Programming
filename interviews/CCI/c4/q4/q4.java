import java.util.ArrayList;
import java.util.LinkedList;

public class q4 {
    public static void main(String[] args) {
        BinaryTree t = buildBST();


        TreeNode n1 = new TreeNode();
        TreeNode n2 = new TreeNode();
        n1.data = 10;
        n2.data = 20;

        t.root.dir.dir.dir.dir = n1;
        t.root.dir.dir.dir.dir.dir = n2;
        
        // Aqui entra o código
        System.out.println(checkBalanced(t));
    }

    public static boolean checkBalanced(BinaryTree tree) {
        return isBalanced(tree.root) != -1;
    }

    public static int isBalanced(TreeNode node) {
        if (node == null) return 0;

        int hl = isBalanced(node.esq);
        int hr = isBalanced(node.dir);

        if (hl == -1 || hr == -1 || Math.abs(hl-hr) > 1) return -1;
        return Math.max(hl, hr) + 1;
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