#include "utils/test_assert.h"
#include <vector>

int maxSubArray(std::vector<int>& nums) {
    int dp[nums.size()];
    dp[0] = nums[0];
    int max = dp[0];
    
    for (int i = 1; i < nums.size(); i++) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]); 
            max = std::max(dp[i], max);
            //std::cout << "get bigger sum, i:" << i 
            //    << ", dp[i - 1]:" << dp[i - 1] 
            //    << ", dp[i]:" << dp[i] << std::endl;
    }
    return max;
}

int main() {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int num = maxSubArray(nums);
    ASSERT_EQUAL(6, num);
    return 0;
}