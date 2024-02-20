#include <iostream>
#include <sstream>
#include "utils/test_assert.h"
#include "utils/list_util.h"

void print_list(ListNode* head) {
    std::stringstream ss;
    ss << head->val << ",";
    ListNode* current = head;
    while(current->next) {
        ss << current->next->val << ",";
        current = current->next;
    }
    std::cout << ss.str() << std::endl;
}

ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        current->next = pre;
        //if (pre) {
        //    std::cout << "current:" << current->val << ", next val:" << pre->val << std::endl;
        //}
        pre = current;
        current = next;
    }
    head = pre;
    
    print_list(head);
    return head;
}

int main() {
    std::vector<int> nodes = {1, 2, 3, 4, 5};
    //print_list(&node1);
    ListNode* after_list = reverseList(create_list(nodes));
    //print_list(&node1);
    //ASSERT_EQUAL(5, after_list->val);
    std::vector<int> except_nodes = {5, 4, 3, 2, 1};
    ASSERT_LIST_EQUAL(create_list(except_nodes), after_list);
    return 0;
}

// g++ src/206_reverse_list.cpp src/utils/*.cpp && ./a.out