#include "utils/print_util.h"
#include "utils/tree_util.h"
#include "utils/test_assert.h"
#include <queue>

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left == nullptr && right == nullptr) {
        return nullptr;
    }
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    return root;
}

int main() {
    std::queue<TreeNode *> nodes;
    nodes.push(new TreeNode(3));
    TreeNode* p = new TreeNode(5);
    nodes.push(p);
    TreeNode* q = new TreeNode(1);
    nodes.push(q);
    nodes.push(new TreeNode(6));
    nodes.push(new TreeNode(2));
    nodes.push(new TreeNode(0));
    nodes.push(new TreeNode(8));
    nodes.push(nullptr);
    nodes.push(nullptr);
    nodes.push(new TreeNode(7));
    nodes.push(new TreeNode(4));
    TreeNode* root = create_tree(nodes);
    //print_tree(root);
    ASSERT_EQUAL(3, lowestCommonAncestor(root, p, q)->val);
    return 0;
}
