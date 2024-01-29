#pragma once

#include <iostream>

#define ASSERT_EQUAL(except, actual) if (except != actual) { std::cout << "assert err, except:" << except << ", actual:" << actual << std::endl; } 