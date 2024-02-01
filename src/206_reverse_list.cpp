#include <iostream>
#include <sstream>
#include "utils/test_assert.h"

struct ListNode {
    int val{0};
    ListNode* next{nullptr};
};

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
        if (pre) {
            std::cout << "current:" << current->val << ", next val:" << pre->val << std::endl;
        }
        pre = current;
        current = next;
    }
    head = pre;
    
    print_list(head);
    return head;
}

int main() {
    ListNode node5;
    node5.val = 5;
    ListNode node4;
    node4.val = 4;
    node4.next = &node5;
    ListNode node3;
    node3.val = 3;
    node3.next = &node4;
    ListNode node2;
    node2.val = 2;
    node2.next = &node3;
    ListNode node1;
    node1.val = 1;
    node1.next = &node2;
    ListNode* head = &node1;
    print_list(&node1);
    head = reverseList(head);
    //print_list(&node1);
    ASSERT_EQUAL(5, head->val);
    return 0;
}

