#include <iostream>
#include "utils/test_assert.h"

struct TreeNode {
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};
    int val;
};

void revert_tree(TreeNode* tree) {
    if (tree == nullptr) {
        return;
    }
    TreeNode* tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;
    revert_tree(tree->left);
    revert_tree(tree->right);
}

int main() {
    TreeNode left = {nullptr, nullptr, 2};
    TreeNode right = {nullptr, nullptr, 3};
    TreeNode root;
    root.left = &left;
    root.right = &right;
    root.val = 1;
    revert_tree(&root);
    std::cout << root.left->val << std::endl;
    ASSERT_EQUAL(3, root.left->val);
    return 0;
}

// g++ -Isrc src/tree/199_tree_right_view.cpp src/utils/*.cpp ; ./a.exe