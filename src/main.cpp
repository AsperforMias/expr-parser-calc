#include "calculator.h"
#include <iostream>
#include <string>

int main() {
    Calculator calculator;
    
    // 如果有命令行参数，直接计算表达式
    // 否则进入交互模式
    calculator.run();
    
    return 0;
}
