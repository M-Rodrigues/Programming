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

int checkHeight(TreeNode * node) {
    if(!node) return -1;

    int leftHeight = checkHeight(node->left);
    if (leftHeight == error) return error;

    int rightHeight = checkHeight(node->right);
    if (rightHeight == error) return error;

    if (abs(rightHeight - leftHeight) > 1) return error;
    else return max(rightHeight,leftHeight) + 1;
}

bool isBalanced(TreeNode * root) {
    return (checkHeight(root) != error);
}

int main() {

    TreeNode * root = new TreeNode(4);

    TreeNode * n1 = new TreeNode(50);
    TreeNode * n2 = new TreeNode(7);

    root->left = n1;
    root->right = n2;

    n1->left = new TreeNode(55);
    n1->right = new TreeNode(90);

    n2->left = new TreeNode(87);

    // n2->left->left = new TreeNode(1);
    // n2->left->left->left = new TreeNode(9);

    printf("The tree is%s balanced!\n",(isBalanced(root) ? "" : " not"));

    return 0;
}