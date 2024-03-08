#include "utils/test_assert.h"
#include "utils/list_util.h"

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) {
        return head;
    }
    ListNode* cur = head;
    ListNode* tail = nullptr;
    int total_cnt = 0;
    while (cur) {
        total_cnt++;    
        if (cur->next == nullptr) {
            tail = cur;
            std::cout << "find tail:" << tail->val << std::endl;
            break;
        }
        cur = cur->next;
    }
    tail->next = head; // 链表成环
    int split_num = total_cnt - (k % total_cnt);
    
    cur = head;
    for (int i = 0; i < split_num - 1; i++) {
        cur = cur->next;
    }
    //std::cout << "skip to split node, split_num:" << split_num
    //    << ", pre:" << pre->val << ", cur:" << cur->val << std::endl;
    ListNode* newhead = cur->next;
    cur->next = nullptr; // 链表断开
    return newhead;
}

int main() {
    std::vector<int> nodes = {1,2,3,4,5};
    ListNode* list = create_list(nodes);
    ListNode* after_list = rotateRight(list, 2);

    std::vector<int> except_nodes = {4,5,1,2,3};
    ASSERT_LIST_EQUAL(create_list(except_nodes), after_list);
    return 0;
}

// g++ src/61_rotate_list.cpp src/utils/*.cpp && ./a.out

