#pragma once
#include "lexer.h"
#include "parser.h"
#include <string>
#include <locale>

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
public:
    double evaluate(const std::string& expression);
    void printHelp() const;
    void run(); // 交互式运行
};
