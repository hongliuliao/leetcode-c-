#include <iostream>
#include <utility> 

struct ListNode {
    int val;
    ListNode* next{nullptr};
};

std::pair<ListNode*, ListNode*> reverse_list(ListNode* head, ListNode* tail) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    std::cout << "start reverse_list, head:" << head->val << ", tail:" << tail->val << std::endl;
    if (tail->next) {
        std::cout << "start reverse_list, tail next:" << tail->next->val << std::endl;
    }
    ListNode* tail_next = tail->next;
    while (cur && cur != tail_next) {
        ListNode* next = cur->next;
        std::cout << "reverse_list, cur:" << cur->val << std::endl;
        cur->next = pre;
        pre = cur;
        cur = next; 
        //std::cout << "reverse_list over, cur:" << cur->val << std::endl;
        if (tail_next) {
            std::cout << "reverse_list over, tail->next:" << tail_next->val << std::endl;
        }   
    }
    std::cout << "reverse_list end, new head:" << pre->val << std::endl;
    std::cout << "reverse_list end, new tail:" << head->val << std::endl;
    return {pre, head};
}

ListNode* reverse_group(ListNode* head, int k) {
    ListNode* new_head = nullptr;
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur) {
        std::cout << "reverse_group, cur:" << cur->val << std::endl;
        ListNode* tail = cur;
        for (int i = 1; i < k; i++) {
            if (tail->next == nullptr) {
                std::cout << "end tail, tail:" << tail->val << std::endl;
                return new_head;
            }
            std::cout << "search tail, cur tail:" << tail->val << std::endl;
            tail = tail->next;
        }
        //std::cout << "reverse_group, cur:" << cur->val << ", tail:" << tail->val << std::endl;
        ListNode* next = tail->next;
        std::pair<ListNode*, ListNode*> after_nodes = reverse_list(cur, tail);
        ListNode* after_head = after_nodes.first;
        if (new_head == nullptr) {
            new_head = after_head;
        }
        ListNode* new_tail = after_nodes.second;
        if (pre) {
            pre->next = after_head;
            std::cout << "link group, pre:" << pre->val << ", next:" << next->val << std::endl;
        }
        
        new_tail->next = next;
        //std::cout << "link group, pre:" << pre->val << ", next:" << next->val << std::endl;
        pre = new_tail;
        cur = next;
    }
    return new_head;
}

void print_list(ListNode* head) {
    int i = 0;
    while (head) {
        std::cout << "print list[" << i << "], val:" << head->val << std::endl;
        i++;
        head = head->next;
    }
}

int main() {
    ListNode node1;
    node1.val = 1;
    ListNode node2;
    node2.val = 2;
    ListNode node3;
    node3.val = 3;
    ListNode node4;
    node4.val = 4;
    ListNode node5;
    node5.val = 5;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    ListNode* newhead = reverse_group(&node1, 2);
    print_list(newhead);
    return 0;
}