#include "calculator.h"
#include <iostream>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#endif

double Calculator::evaluate(const std::string& expression) {
    try {
        // 词法分析
        Lexer lexer(expression);
        auto tokens = lexer.tokenize();
        
        // 语法分析
        Parser parser(tokens);
        auto ast = parser.parse();
        
        // 计算结果
        return ast->evaluate();
    } catch (const std::exception& e) {
        throw CalculatorException("计算错误：" + std::string(e.what()));
    }
}

void Calculator::printHelp() const {
    std::cout << "\n=== 表达式计算器 ===" << std::endl;
    std::cout << "支持的操作：" << std::endl;
    std::cout << "  + : 加法" << std::endl;
    std::cout << "  - : 减法" << std::endl;
    std::cout << "  * : 乘法" << std::endl;
    std::cout << "  / : 除法" << std::endl;
    std::cout << "  ^ : 乘方" << std::endl;
    std::cout << "  ( ) : 括号" << std::endl;
    std::cout << "\n支持的数学函数：" << std::endl;
    std::cout << "  sqrt(x) : 平方根" << std::endl;
    std::cout << "  sin(x)  : 正弦函数" << std::endl;
    std::cout << "  cos(x)  : 余弦函数" << std::endl;
    std::cout << "  tan(x)  : 正切函数" << std::endl;
    std::cout << "  log(x)  : 自然对数" << std::endl;
    std::cout << "  exp(x)  : 指数函数" << std::endl;
    std::cout << "\n示例表达式：" << std::endl;
    std::cout << "  2 + 3 * 4" << std::endl;
    std::cout << "  (2 + 3) * 4" << std::endl;
    std::cout << "  2^3 + 1" << std::endl;
    std::cout << "  sqrt(16) + sin(0)" << std::endl;
    std::cout << "  -5 + 3" << std::endl;
    std::cout << "\n输入 'help' 显示帮助，输入 'quit' 或 'exit' 退出" << std::endl;
    std::cout << "==================" << std::endl;
}

void Calculator::run() {
#ifdef _WIN32
    // 设置Windows控制台支持UTF-8输出，只影响显示
    SetConsoleOutputCP(65001);  // UTF-8
#endif
    
    std::cout << "欢迎使用表达式计算器！" << std::endl;
    printHelp();
      std::string input;
    while (true) {
        std::cout << "\n计算器> ";
        
        // 检查输入流状态，如果失败则退出
        if (!std::getline(std::cin, input)) {
            std::cout << "\n输入流结束，程序退出。" << std::endl;
            break;
        }
        
        if (input.empty()) {
            continue;
        }
        
        if (input == "quit" || input == "exit") {
            std::cout << "再见！" << std::endl;
            break;
        }
        
        if (input == "help") {
            printHelp();
            continue;
        }
        
        try {
            double result = evaluate(input);
            std::cout << "结果: " << result << std::endl;
        } catch (const CalculatorException& e) {
            std::cout << "错误: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "未知错误: " << e.what() << std::endl;
        }
    }
}
