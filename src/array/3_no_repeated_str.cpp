#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include "utils/test_assert.h"

int lengthOfLongestSubstring(std::string s) {
    int max = 0;
        
    int n = s.size();
    for (int i = 0; i < n; i++) {
        std::unordered_set<char> set;
        set.insert(s[i]);
        int j = i+1;
        for (int j = i + 1; j < n; j ++) {
            if (set.count(s[j])) {
                break;
            }   
            set.insert(s[j]);
            std::cout << "insert no repeat char:" << s[j] << std::endl;
        }
        max = std::max(max, (int)set.size());
    }
    return max;
}

int main() {
    int len = lengthOfLongestSubstring("abcabcbb");
    ASSERT_EQUAL(3, len);
    return 0;
}