#include "utils/test_assert.h"
#include "utils/print_util.h"
#include "utils/list_util.h"

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr || list2 == nullptr) {
            if (list1 == nullptr) {
                return list2;
            }
            if (list2 == nullptr) {
                return list1;
            }
        }
        ListNode* result = list1->val <= list2->val ? list1 : list2;
        
        std::vector<ListNode*> nodes;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                nodes.push_back(list1);
                list1 = list1->next;
            }
            if (list1 && list2 && list1->val == list2->val) {
                nodes.push_back(list1);
                nodes.push_back(list2);
                list1 = list1->next;
                list2 = list2->next;
            }
            if (list1 && list2 && list1->val > list2->val) {    
                nodes.push_back(list2);
                list2 = list2->next;
            }
        }
        while (list1) {
            nodes.push_back(list1);
            list1 = list1->next;
        }
        while (list2) {
            nodes.push_back(list2);
            list2 = list2->next;
        }
        for (int i = 0; i < nodes.size() - 1; i++) {
            ListNode* n = nodes[i];
            n->next = nodes[i+1];
        }
        nodes[nodes.size()-1]->next = nullptr;
        
        return result;
}

int main() {
    std::vector<int> nodes1 = {1,2,4};
    std::vector<int> nodes2 = {1,3,4};
    ListNode* merge_nodes = mergeTwoLists(create_list(nodes1), create_list(nodes2));
    std::vector<int> except_nodes = {1,1,2,3,4,4};
    ListNode* except_list = create_list(except_nodes);
    ASSERT_LIST_EQUAL(except_list, merge_nodes);
    return 0;
}

// g++ src/21_merge_sort_list.cpp src/utils/*.cpp && ./a.out