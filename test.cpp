#include "calculator.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    Calculator calculator;
    
    // 测试用例
    std::vector<std::pair<std::string, double>> test_cases = {
        {"2 + 3", 5.0},
        {"2 + 3 * 4", 14.0},
        {"(2 + 3) * 4", 20.0},
        {"2^3", 8.0},
        {"2^3 + 1", 9.0},
        {"-5 + 3", -2.0},
        {"10 / 2", 5.0},
        {"3.14 * 2", 6.28},
        {"(3 + 4) * (2 - 1)", 7.0},
        // 新增测试用例
        {"2^3^2", 512.0},  // 右结合测试: 2^(3^2) = 2^9 = 512
        {"2 * 3 + 4 * 5", 26.0},  // 多项计算
        {"((2 + 3) * 4) / 2", 10.0},  // 嵌套括号
        {"0.5 + 0.5", 1.0},  // 小数精度
        {"-(-5)", 5.0},  // 双重负号
        {"2 + -3", -1.0}  // 正负混合
    };
    
    std::cout << "Expression Calculator Test Results:" << std::endl;
    std::cout << "====================================" << std::endl;
    
    bool allPassed = true;
    
    for (const auto& test : test_cases) {
        try {
            double result = calculator.evaluate(test.first);
            bool passed = std::abs(result - test.second) < 0.001;
            
            std::cout << "Expression: " << test.first << std::endl;
            std::cout << "Expected: " << test.second << std::endl;
            std::cout << "Got: " << result << std::endl;
            std::cout << "Status: " << (passed ? "PASS" : "FAIL") << std::endl;
            std::cout << "--------------------" << std::endl;
            
            if (!passed) {
                allPassed = false;
            }
        } catch (const std::exception& e) {
            std::cout << "Expression: " << test.first << std::endl;
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Status: FAIL" << std::endl;
            std::cout << "--------------------" << std::endl;
            allPassed = false;
        }
    }
    
    std::cout << "\nOverall Result: " << (allPassed ? "ALL TESTS PASSED" : "SOME TESTS FAILED") << std::endl;
    
    return allPassed ? 0 : 1;
}
