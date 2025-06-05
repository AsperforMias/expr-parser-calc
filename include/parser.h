#pragma once
#include "lexer.h"
#include <memory>

// 抽象语法树节点基类
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual double evaluate() = 0;
};

// 数字节点
class NumberNode : public ASTNode {
private:
    double value;
    
public:
    NumberNode(double val) : value(val) {}
    double evaluate() override { return value; }
};

// 二元操作节点
class BinaryOpNode : public ASTNode {
private:
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;
    TokenType operator_type;
    
public:
    BinaryOpNode(std::unique_ptr<ASTNode> l, TokenType op, std::unique_ptr<ASTNode> r)
        : left(std::move(l)), operator_type(op), right(std::move(r)) {}
    
    double evaluate() override;
};

// 一元操作节点
class UnaryOpNode : public ASTNode {
private:
    std::unique_ptr<ASTNode> operand;
    TokenType operator_type;
    
public:
    UnaryOpNode(TokenType op, std::unique_ptr<ASTNode> operand)
        : operator_type(op), operand(std::move(operand)) {}
    
    double evaluate() override;
};

// 数学函数节点
class FunctionNode : public ASTNode {
private:
    TokenType function_type;
    std::unique_ptr<ASTNode> argument;
    
public:
    FunctionNode(TokenType func_type, std::unique_ptr<ASTNode> arg)
        : function_type(func_type), argument(std::move(arg)) {}
    
    double evaluate() override;
};

// 语法分析器类
class Parser {
private:
    std::vector<Token> tokens;
    size_t current_token_index;
    Token current_token;
    
    void advance();
    void eat(TokenType expected_type);
    
    std::unique_ptr<ASTNode> expression();
    std::unique_ptr<ASTNode> term();
    std::unique_ptr<ASTNode> factor();
    std::unique_ptr<ASTNode> power();
    
public:
    Parser(const std::vector<Token>& tokens);
    std::unique_ptr<ASTNode> parse();
};
