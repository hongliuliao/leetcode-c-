#include "utils/test_assert.h"

int fib(int n) {
    if (n < 2) {
        return n;
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i-2]) % 1000000007;
    }
    
    return dp[n] % 1000000007;
}

int main() {
    ASSERT_EQUAL(0, fib(0));
    ASSERT_EQUAL(1, fib(1));
    ASSERT_EQUAL(1, fib(2));
    ASSERT_EQUAL(2, fib(3));
    ASSERT_EQUAL(3, fib(4));
    return 0;
}