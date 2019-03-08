#include <bits/stdc++.h>
using namespace std;

#define error -1e6

class TreeNode {
public:
    int data;
    TreeNode * left = NULL;
    TreeNode * right = NULL;

    TreeNode(int data = 0): data(data) {}
};

bool isBST(TreeNode * node) {
    if (!node) return false;

    if (!node->left && !node->right) 
        return true;
    if (node->left && !node->right) 
        return (node->data >= node->left->data) && isBST(node->left);
    if (!node->left && node->right)
        return (node->data < node->right->data) && isBST(node->right);

    bool leftOk = node->data >= node->left->data;
    bool rightOk = node->data < node->right->data;

    return leftOk && rightOk && isBST(node->left) && isBST(node->right);
}

int main() {
    TreeNode * root = new TreeNode(30);

    TreeNode * n1 = new TreeNode(10);
    TreeNode * n2 = new TreeNode(40);

    root->left = n1;
    root->right = n2;

    n1->left = new TreeNode(5);
    n1->right = new TreeNode(12);

    n2->left = new TreeNode(37);

    printf("The tree is%s a BST\n",(isBST(root) ? "" : " not"));

    return 0;
}