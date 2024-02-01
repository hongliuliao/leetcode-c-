#include "utils/test_assert.h"
#include "utils/print_util.h"

int trap(std::vector<int>& height) {
    int left_max[height.size()];
    left_max[0] = height[0];
    for (int i = 1; i < height.size(); i++) {
        left_max[i] = std::max(left_max[i-1], height[i]);
        //std::cout << "left_max[" << i << "]" << left_max[i] << std::endl;
    }   
    int right_max[height.size()];
    right_max[height.size() - 1] = height[height.size() - 1]; 
    for (int i = height.size() - 2; i >= 0; i--) {
        right_max[i] = std::max(height[i], right_max[i+1]);
        //std::cout << "right_max[" << i << "]" << right_max[i] << std::endl;
    }   
    int total = 0;
    for (int i = 0; i < height.size(); i++) {
        total += std::min(left_max[i], right_max[i]) - height[i];
    }   
    return total;
}

int main(){
    std::vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    int num = trap(heights);
    ASSERT_EQUAL(6, num);
    return 0;
}
