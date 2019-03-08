#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public: 
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int data = 0): data(data) {}
};

vector<vector<int>> createLinkedLists(TreeNode * treeRoot) {
    vector<vector<int>> finalList;
    if (treeRoot) {
        queue<pair<TreeNode *,int>> q;

        q.push({treeRoot,0});
        while (!q.empty()) {
            pair<TreeNode *,int> P = q.front(); q.pop();
            TreeNode * node = P.first;
            int d = P.second;

            if (finalList.size() <= d) finalList.push_back({});
            finalList[d].push_back(node->data);

            if (node->left) q.push({node->left,d+1});
            if (node->right) q.push({node->right,d+1});
        }
    }
    return finalList;
}

void preOrder(TreeNode * node) {
    if (node) {
        printf("%d ",node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
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

    vector<vector<int>> Lists = createLinkedLists(root);

    for (int i = 0; i < Lists.size(); i++) {
        printf("nivel %d -> ",i);
        for (int v : Lists[i]) printf("%d ",v);
        printf("\n");
    }

    return 0;
};