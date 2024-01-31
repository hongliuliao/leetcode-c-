#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>

#include <iostream>
#include <chrono>

using std::vector;
using std::unordered_map;

class Timer {
public:
    Timer() {
        // 开始计时
        start_time = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        // 结束计时并计算耗时
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "耗时: " << duration.count() << "us" << std::endl;
    }

private:
    // 开始时间
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

void print_vector(std::vector<int>& input, std::string msg = "") {
    for (int i = 0; i < input.size(); i++) {
        std::cout << msg << " vector[" << i << "]:" << input[i] << std::endl; 
    }
}
