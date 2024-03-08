
#include "utils/print_util.h"
#include "utils/test_assert.h"
#include <vector>

std::vector<std::vector<int>> two_sum(std::vector<int>& nums, int idx, int target) {
    std::vector<std::vector<int>> result;
    std::unordered_map<int, std::vector<int>> num_idxs;
    for (int i = idx; i < nums.size(); i++) {
        int num = nums[i]; 
        if (num_idxs.count(target - num)) {
            for (int pair_num_idx : num_idxs[target - num]) {
                std::vector<int> group;
                group.push_back(nums[idx - 1]);
                group.push_back(nums[i]);
                group.push_back(nums[pair_num_idx]);
                result.push_back(group);
                std::cout << "find pair_num, num:" << num << ", pair_num_idx:" << pair_num_idx << std::endl;
            }
        } else {
            num_idxs[num].push_back(i);
        }
    }
    return result;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    std::vector<std::vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i]; 
        int target = -num;
        std::vector<std::vector<int>> tmp_result = two_sum(nums, i+1, target);
        result.insert(result.begin(), tmp_result.begin(), tmp_result.end());
    }
    return result; 
}

int main() {
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ret = threeSum(nums);
    for (auto& group : ret) {
        print_vector(group);
        std::cout << " " << std::endl;
    }
    ASSERT_EQUAL(3, ret.size());
    return 0;
}
