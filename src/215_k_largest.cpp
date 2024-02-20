#include <vector>
#include <iostream>
#include "utils/print_util.h"
#include "utils/test_assert.h"

using std::vector;

void quick_sort(vector<int>& nums, int i, int j, int k) {
    if (i >= j) {
        return;
    }
    int start = i;
    int end = j;
    int first = nums[i];
    while (i < j) {
        while (i < j && nums[j] > first) {
            j--;
        }
        if (i < j) {
            nums[i] = nums[j];
            i++;
        }
        
        while (i < j && nums[i] < first) {
            i++;
        }
        if (i < j) {
            nums[j] = nums[i];
            j--;
        }
    }
    nums[i] = first;
    quick_sort(nums, start, i-1, k);
    quick_sort(nums, i+1, end, k);
    return;
}

int findKthLargest(vector<int>& nums, int k) {
    int i = 0;
    int j = nums.size() - 1;
    quick_sort(nums, i, j, k);
    //std::cout << "quick sort over, size:" << nums.size() << ", k:" << k
    //    << std::endl;
    //print_vector(nums);
    return nums[nums.size() - k];
}

int main() {
    std::vector<int> nums = {3,2,1,5,6,4};
    int k = 3;
    int ret = findKthLargest(nums, k);
    /*
    for (int i : nums) {
        std::cout << i << std::endl;
    }
    */
    //std::cout << "ret: " << nums[ret] << std::endl;
    ASSERT_EQUAL(4, ret);
 
    //k = 50000;
    //ret = findKthLargest(nums, k);
    //ASSERT_EQUAL(1, ret);
    return 0;
}

// g++ src/206_reverse_list.cpp src/utils/*.cpp && ./a.out