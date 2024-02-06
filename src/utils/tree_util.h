#pragma once

#include <queue>
#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* create_tree(std::queue<TreeNode*>& nodes) {
    if (nodes.empty()) {
        return nullptr;
    }
    TreeNode* root = nodes.front(); // 取出根节点
    nodes.pop();
    std::queue<TreeNode*> q; // 使用一个队列来追踪当前层的节点
    q.push(root);
    
    while (!nodes.empty()) {
        TreeNode* parent = q.front();
        q.pop();
        
        // 分配左子节点
        if (!nodes.empty()) {
            TreeNode* left_child = nodes.front();
            nodes.pop();
            if (left_child) { // 如果左子节点非空
                parent->left = left_child;
                //std::cout << "add left node:" << left_child->val << ", nodes size:" << nodes.size() << std::endl;
                q.push(left_child);
            }
        }
        
        // 分配右子节点
        if (!nodes.empty()) {
            TreeNode* right_child = nodes.front();
            nodes.pop();
            if (right_child) { // 如果右子节点非空
                parent->right = right_child;
                q.push(right_child);
            }
        }
    }
    
    return root;
}

// 使用层序遍历来竖直打印树
void print_tree(TreeNode* root) {
    if (!root) return;

    std::queue<TreeNode*> nodesQueue;
    int levelNodes = 0; // 当前层的节点数

    nodesQueue.push(root);
    while (!nodesQueue.empty()) {
        levelNodes = nodesQueue.size(); // 当前层的节点数

        // 遍历当前层的所有节点
        while (levelNodes > 0) {
            TreeNode *node = nodesQueue.front();
            nodesQueue.pop();
            // 打印当前节点，并将子节点加入队列
            if (node) {
                std::cout << node->val << " ";
                nodesQueue.push(node->left);
                nodesQueue.push(node->right);
            } else {
                // 对于空节点也进行占位，以保持结构
                std::cout << "N ";
            }
            levelNodes--;
        }
        std::cout << std::endl; // 该层所有节点打印完毕，换行
    }
}