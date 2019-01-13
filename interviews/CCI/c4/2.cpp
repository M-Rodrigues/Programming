#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode * left = NULL;
    TreeNode * right = NULL;

    TreeNode(int data = 0): data(data) {}
};

TreeNode * createMinimalBST(int * arr, int l, int r) {
    if (l > r) return NULL;

    int m = (l+r)/2;

    printf("%d\n",arr[m]);
    TreeNode * node = new TreeNode(arr[m]);

    node->left = createMinimalBST(arr,l,m-1);
    node->right = createMinimalBST(arr,m+1,r);

    return node;
}

void inOrder(TreeNode * node) {
    if (node) {
        printf("%d ",node->data);
        inOrder(node->left);
        inOrder(node->right);
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    TreeNode * root = createMinimalBST(arr, 0, 9);

    inOrder(root);
    printf("\n");

    return 0;
}
