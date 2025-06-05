#pragma once
#include "lexer.h"
#include "parser.h"
#include <string>
#include <locale>
#include <memory>

// 计算器异常类
class CalculatorException : public std::exception {
private:
    std::string message;
    
public:
    CalculatorException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

// 计算器主类
class Calculator {
private:
    // 缓存最后解析的AST以避免重复解析相同表达式
    mutable std::string last_expression;
    mutable std::unique_ptr<ASTNode> cached_ast;
    
public:
    double evaluate(const std::string& expression);
    void printHelp() const;
    void run(); // 交互式运行
    void clearCache(); // 清空缓存
    
    // 性能统计
    struct Statistics {
        size_t expressions_evaluated = 0;
        size_t cache_hits = 0;
        double total_evaluation_time = 0.0;
    };
    Statistics getStatistics() const { return stats; }
    void resetStatistics() { stats = {}; }
    
private:
    mutable Statistics stats;
};
