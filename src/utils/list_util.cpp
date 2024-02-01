#include "list_util.h"

ListNode* create_list(std::vector<int>& nodes) {
    int array_size = nodes.size();
    
    std::vector<ListNode*> tmp_nodes;
    for (int i = 0; i < array_size; i++) {
        ListNode* n = new ListNode(nodes[i]);
        tmp_nodes.push_back(n);
    }
    for (int i = 0; i < array_size - 1; i++) {
        tmp_nodes[i]->next = tmp_nodes[i+1];
    } 
    return tmp_nodes[0];
};