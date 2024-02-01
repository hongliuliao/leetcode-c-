#pragma once

#include "list_util.h"

#include <iostream>

#define ASSERT_EQUAL(except, actual) \
    if (except != actual) { \
        std::cout << "assert err, except:" << except << ", actual:" << actual << std::endl; \
    } 

void ASSERT_LIST_EQUAL(ListNode* list1, ListNode* list2) { \
    while(list1 && list2) { \
        if (list1->val != list2->val) { \
            std::cout << "assert err, except:" << list1->val \
                 << ", actual:" << list2->val << std::endl; \
            break; \
        } \
        list1 = list1->next; \
        list2 = list2->next; \
    } \
    if (list1 != nullptr || list2 != nullptr) { \
        std::cout << "assert err, list1 != nullptr:" << (list1 != nullptr) \
                 << ", list2!= nullptr:" << (list2 != nullptr) << std::endl; \
    }
}