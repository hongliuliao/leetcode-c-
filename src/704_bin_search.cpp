#include <vector>
#include <iostream>
#include "utils/test_assert.h"

using std::vector;

int search(vector<int>& nums, int target) {
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j) {
        int mid = (i+j) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> nums = {-1,0,3,5,9,12};
    int num = search(nums, 3);
    ASSERT_EQUAL(2, num);
}