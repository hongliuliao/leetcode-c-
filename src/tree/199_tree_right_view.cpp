#include "utils/tree_util.h"
#include "utils/test_assert.h"

#include <queue>
#include <unordered_map>

std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    std::unordered_map<int, int> level_last_node_val;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* n = q.front();
        q.pop();
        level_last_node_val[n->level] = n->val;
        std::cout << "put node to map, level:" << n->level
            << ", node val:" << n->val << std::endl;
        if (n->left) {
            n->left->level = n->level + 1;
            q.push(n->left);
        }
        if (n->right) {
            n->right->level = n->level + 1;
            q.push(n->right);
        }
    }
    for (int i = 0; i < level_last_node_val.size(); i++) {
        int last_node_val = level_last_node_val[i];
        result.push_back(last_node_val);
        std::cout << "put right node to result, level:" << i
            << ", node val:" << last_node_val << std::endl;
    }
    return result;
}

int main() {
    std::queue<TreeNode *> nodes;
    nodes.push(new TreeNode(1));
    TreeNode* p = new TreeNode(2);
    nodes.push(p);
    TreeNode* q = new TreeNode(3);
    nodes.push(q);
    nodes.push(nullptr);
    nodes.push(new TreeNode(5));
    nodes.push(nullptr);
    nodes.push(new TreeNode(4));
    TreeNode* root = create_tree(nodes);
    std::vector<int> actual_array = rightSideView(root);
    std::vector<int> except_array = {1,3,4};
    ASSERT_VECTOR_EQUAL(except_array, actual_array);
}

// g++ -Isrc src/tree/199_tree_right_view.cpp src/utils/*.cpp ; ./a.exe