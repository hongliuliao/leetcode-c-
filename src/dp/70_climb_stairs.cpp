#include "utils/test_assert.h"

int climbStairs(int n) {
    if (n <= 1) {
        return n;
    }
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    std::cout << "climbStairs n:" << n << ", dp[" << n << "]:"  << dp[n] << std::endl;
    return dp[n];
}

int main() {
    ASSERT_EQUAL(2, climbStairs(2));
    ASSERT_EQUAL(3, climbStairs(3));
    ASSERT_EQUAL(5, climbStairs(4));
    return 0;
}