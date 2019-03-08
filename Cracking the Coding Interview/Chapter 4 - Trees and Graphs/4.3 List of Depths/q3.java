import java.util.ArrayList;
import java.util.LinkedList;

public class q3 {
    public static void main(String[] args) {
        ArrayList<LinkedList<TreeNode>> depthList = new ArrayList<LinkedList<TreeNode>>();
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

        depthList = ListOfDepths(t);

        for (int i = 0; i < depthList.size(); i++) {
            String s = (i+1) + ": ";
            LinkedList<TreeNode> list = depthList.get(i);

            for (TreeNode node : list) {
                s = s + node.data + ", ";
            }

            System.out.println(s);
        }
    }

    public static ArrayList<LinkedList<TreeNode>> ListOfDepths(BinaryTree tree) {
        ArrayList<LinkedList<TreeNode>> arr = new ArrayList<LinkedList<TreeNode>>();
        buildList(tree.root, arr, 0);
        return arr;
    }

    public static void buildList(TreeNode node, ArrayList<LinkedList<TreeNode>> arr, int level) {
        if (node == null) return;

        if (level == arr.size()) {
            arr.add(new LinkedList<TreeNode>());
        }

        arr.get(level).add(node);

        buildList(node.esq, arr, level+1);
        buildList(node.dir, arr, level+1);
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