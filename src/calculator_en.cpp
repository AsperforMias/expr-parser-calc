#include "calculator.h"
#include <iostream>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <fcntl.h>
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
        throw CalculatorException("Calculation Error: " + std::string(e.what()));
    }
}

void Calculator::printHelp() const {
    std::cout << "\n=== Expression Calculator ===" << std::endl;
    std::cout << "Supported operations:" << std::endl;
    std::cout << "  + : Addition" << std::endl;
    std::cout << "  - : Subtraction" << std::endl;
    std::cout << "  * : Multiplication" << std::endl;
    std::cout << "  / : Division" << std::endl;
    std::cout << "  ^ : Power" << std::endl;
    std::cout << "  ( ) : Parentheses" << std::endl;
    std::cout << "\nExample expressions:" << std::endl;
    std::cout << "  2 + 3 * 4" << std::endl;
    std::cout << "  (2 + 3) * 4" << std::endl;
    std::cout << "  2^3 + 1" << std::endl;
    std::cout << "  -5 + 3" << std::endl;
    std::cout << "\nInput 'help' for help, 'quit' or 'exit' to quit" << std::endl;
    std::cout << "==================" << std::endl;
}

void Calculator::run() {
#ifdef _WIN32
    // 设置Windows控制台支持UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    // 启用ANSI转义序列支持
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
    
    std::cout << "Welcome to Expression Calculator!" << std::endl;
    printHelp();
      std::string input;
    while (true) {
        std::cout << "\nCalculator> ";
        
        // 检查输入流状态，如果失败则退出
        if (!std::getline(std::cin, input)) {
            std::cout << "\nInput stream ended, program exiting." << std::endl;
            break;
        }
        
        if (input.empty()) {
            continue;
        }
        
        if (input == "quit" || input == "exit") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        
        if (input == "help") {
            printHelp();
            continue;
        }
        
        try {
            double result = evaluate(input);
            std::cout << "Result: " << result << std::endl;
        } catch (const CalculatorException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Unknown error: " << e.what() << std::endl;
        }
    }
}
