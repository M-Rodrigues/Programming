import java.util.ArrayList;
import java.util.LinkedList;

public class q6 {
    public static void main(String[] args) {
        BinaryTree t = buildBST();

        for (int i = 0; i < 25; i++) {
            System.out.println("Sucessor de " + i + ": " + successor(i, t).data);
        }
    }

    public static TreeNode successor(int num, BinaryTree tree) {
        TreeNode leaf = findLeaf(num, tree.root);
        return findSuccessor(leaf, leaf);
    }

    public static TreeNode findLeaf(int num, TreeNode node) {
        if (node == null) return null;

        if (num > node.data && node.dir != null)
            return findLeaf(num, node.dir);
        else if(node.esq != null && node.esq != null) 
            return findLeaf(num, node.esq);
        else return node;
    }

    public static TreeNode findSuccessor(TreeNode node, TreeNode maxNode) {
        if (node == null) return maxNode;

        if (node.data > maxNode.data) maxNode = node;

        return findSuccessor(node.parent, maxNode);
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

        if(n.dir != null) n.dir.parent = n;
        if(n.esq != null) n.esq.parent = n;

        return n;
    }
}