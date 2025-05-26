#include "parser.h"
#include <stdexcept>
#include <cmath>

double BinaryOpNode::evaluate() {
    double left_val = left->evaluate();
    double right_val = right->evaluate();
    
    switch (operator_type) {
        case TokenType::PLUS:
            return left_val + right_val;
        case TokenType::MINUS:
            return left_val - right_val;
        case TokenType::MULTIPLY:
            return left_val * right_val;
        case TokenType::DIVIDE:
            if (right_val == 0.0) {
                throw std::runtime_error("除零错误");
            }
            return left_val / right_val;
        case TokenType::POWER:
            return std::pow(left_val, right_val);
        default:
            throw std::runtime_error("未知的二元操作符");
    }
}

double UnaryOpNode::evaluate() {
    double operand_val = operand->evaluate();
    
    switch (operator_type) {
        case TokenType::PLUS:
            return operand_val;
        case TokenType::MINUS:
            return -operand_val;
        default:
            throw std::runtime_error("未知的一元操作符");
    }
}

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), current_token_index(0), current_token(TokenType::END) {
    if (!tokens.empty()) {
        current_token = tokens[0];
    }
}

void Parser::advance() {
    current_token_index++;
    if (current_token_index < tokens.size()) {
        current_token = tokens[current_token_index];
    }
}

void Parser::eat(TokenType expected_type) {
    if (current_token.type == expected_type) {
        advance();
    } else {
        throw std::runtime_error("语法错误：期望令牌类型不匹配");
    }
}

std::unique_ptr<ASTNode> Parser::expression() {
    auto node = term();
    
    while (current_token.type == TokenType::PLUS || current_token.type == TokenType::MINUS) {
        TokenType op = current_token.type;
        eat(op);
        auto right = term();
        node = std::make_unique<BinaryOpNode>(std::move(node), op, std::move(right));
    }
    
    return node;
}

std::unique_ptr<ASTNode> Parser::term() {
    auto node = power();
    
    while (current_token.type == TokenType::MULTIPLY || current_token.type == TokenType::DIVIDE) {
        TokenType op = current_token.type;
        eat(op);
        auto right = power();
        node = std::make_unique<BinaryOpNode>(std::move(node), op, std::move(right));
    }
    
    return node;
}

std::unique_ptr<ASTNode> Parser::power() {
    auto node = factor();
    
    while (current_token.type == TokenType::POWER) {
        TokenType op = current_token.type;
        eat(op);
        auto right = factor(); // 右结合
        node = std::make_unique<BinaryOpNode>(std::move(node), op, std::move(right));
    }
    
    return node;
}

std::unique_ptr<ASTNode> Parser::factor() {
    Token token = current_token;
    
    if (token.type == TokenType::PLUS) {
        eat(TokenType::PLUS);
        auto operand = factor();
        return std::make_unique<UnaryOpNode>(TokenType::PLUS, std::move(operand));
    }
    
    if (token.type == TokenType::MINUS) {
        eat(TokenType::MINUS);
        auto operand = factor();
        return std::make_unique<UnaryOpNode>(TokenType::MINUS, std::move(operand));
    }
    
    if (token.type == TokenType::NUMBER) {
        eat(TokenType::NUMBER);
        return std::make_unique<NumberNode>(token.value);
    }
    
    if (token.type == TokenType::LEFT_PAREN) {
        eat(TokenType::LEFT_PAREN);
        auto node = expression();
        eat(TokenType::RIGHT_PAREN);
        return node;
    }
    
    throw std::runtime_error("语法错误：无效的因子");
}

std::unique_ptr<ASTNode> Parser::parse() {
    auto result = expression();
    if (current_token.type != TokenType::END) {
        throw std::runtime_error("语法错误：表达式末尾有多余字符");
    }
    return result;
}
