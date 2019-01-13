import java.util.ArrayList;

public class q9 {
    public static void main(String[] args) {
        BinaryTree tree = buildBST();

        ArrayList<ArrayList<TreeNode>> ans = BSTSequence(tree);
        
        showList(ans);
    }
    
    public static ArrayList<ArrayList<TreeNode>> BSTSequence(BinaryTree tree) {
        ArrayList<TreeNode> left = new ArrayList<TreeNode>();
        ArrayList<TreeNode> right = new ArrayList<TreeNode>();
        ArrayList<TreeNode> ans = new ArrayList<TreeNode>();
        ArrayList<ArrayList<TreeNode>> complete = new ArrayList<ArrayList<TreeNode>>();

        ans.add(tree.root);

        preOrder(tree.root.esq, left);
        preOrder(tree.root.dir, right);
        
        BSTSequence(left,0,right,0,ans, complete);

        return complete;
    }

    public static void BSTSequence(
        ArrayList<TreeNode> left, int il, 
        ArrayList<TreeNode> right, int ir,
        ArrayList<TreeNode> arr,
        ArrayList<ArrayList<TreeNode>> all) {
        
        if (il == left.size() && ir == right.size()) {
            all.add((ArrayList<TreeNode>) arr.clone()); return;
        }

        if (il != left.size()) {
            arr.add(left.get(il)); il++;
            BSTSequence(left, il, right, ir, arr, all); il--;
            arr.remove(arr.size()-1);
        }
        
        if (ir != right.size()) {
            arr.add(right.get(ir)); ir++;
            BSTSequence(left, il, right, ir, arr, all); ir--; 
            arr.remove(arr.size()-1);
        }
    }

    public static void showList(ArrayList<ArrayList<TreeNode>> arr) {
        for (ArrayList<TreeNode> seq : arr) {
            for (int i = 0; i < seq.size(); i++) {
                System.out.print(seq.get(i).data + (i == seq.size()-1 ? "\n" : ", "));
            }
        }
    }

    public static void preOrder(TreeNode node, ArrayList<TreeNode> arr) {
        if (node == null) return;

        arr.add(node);
        preOrder(node.esq, arr);
        preOrder(node.dir, arr);
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