#include "utils/test_assert.h"

#include <unordered_set>
#include <cstring>

int longestConsecutive(std::vector<int>& nums) {
    int max = 0;
    std::unordered_set<int> num_cnt_set;
    for (int i = 0; i < nums.size(); i++) {
        int cur = nums[i];
        num_cnt_set.insert(cur);
    }
    
    for (int num : num_cnt_set) {
        int left = num - 1;
        int right = num + 1;
        int seq = 1;
        if (!num_cnt_set.count(left)) {
            while (num_cnt_set.count(right)) {
                num_cnt_set.erase(right);
                seq++;
                right++;
            }
            max = std::max(max, seq);
        } 
    }
    return max;
}

int main() {
    std::vector<int> nums = {100,4,200,1,3,2};
    int num = longestConsecutive(nums);
    ASSERT_EQUAL(4, num);
    return 0;
}