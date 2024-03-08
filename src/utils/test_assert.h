#pragma once

#include "list_util.h"

#include <iostream>
#include <vector>

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

void ASSERT_VECTOR_EQUAL(std::vector<int>& except_array, std::vector<int>& actual_array) { \
    if (except_array.size() != actual_array.size()) { \
        std::cout << "assert err, except array size:" << except_array.size() \
                << ", actual array size:" << actual_array.size() << std::endl; \
        return; \
    } \
    for (int i = 0; i < except_array.size(); i++) { \
        if (except_array[i] != actual_array[i]) { \
            std::cout << "assert err, except:" << except_array[i] \
                 << ", actual:" << actual_array[i] << ", idx:" << i << std::endl; \
            break; \
        } \
    } 
}