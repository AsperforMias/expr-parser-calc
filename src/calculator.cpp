#include "calculator.h"
#include <iostream>
#include <stdexcept>
#include <chrono>

double Calculator::evaluate(const std::string& expression) {
    auto start_time = std::chrono::high_resolution_clock::now();
    
    try {
        // 检查缓存
        if (last_expression == expression && cached_ast) {
            stats.cache_hits++;
            auto result = cached_ast->evaluate();
            
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end_time - start_time).count();
            stats.total_evaluation_time += duration;
            stats.expressions_evaluated++;
            
            return result;
        }
        
        // 词法分析
        Lexer lexer(expression);
        auto tokens = lexer.tokenize();
        
        // 语法分析
        Parser parser(tokens);
        auto ast = parser.parse();
        
        // 缓存AST
        last_expression = expression;
        cached_ast = std::move(ast);
        
        // 计算结果
        auto result = cached_ast->evaluate();
        
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration<double>(end_time - start_time).count();
        stats.total_evaluation_time += duration;
        stats.expressions_evaluated++;
        
        return result;
    } catch (const std::exception& e) {
        throw CalculatorException("Calculation Error: " + std::string(e.what()));
    }
}

void Calculator::clearCache() {
    last_expression.clear();
    cached_ast.reset();
}

void Calculator::printHelp() const {
    // 默认英文帮助信息（可被子类重写）
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
    // 基础版本，主要用于测试和库使用
    // UI交互逻辑在 calculator_en.cpp 和 calculator_zh.cpp 中实现
    std::cout << "Expression Calculator (Base Version)" << std::endl;
    std::cout << "For interactive mode, use calculator_en or calculator_zh" << std::endl;
    std::cout << "This is the core calculation engine without UI." << std::endl;
}
