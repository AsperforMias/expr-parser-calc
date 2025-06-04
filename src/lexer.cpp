#include "lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& input) : input(input), position(0), length(input.length()) {
}

char Lexer::currentChar() {
    if (position >= length) {
        return '\0'; // 结束字符
    }
    return input[position];
}

void Lexer::advance() {
    position++;
}

void Lexer::skipWhitespace() {
    while (position < length && std::isspace(currentChar())) {
        advance();
    }
}

double Lexer::readNumber() {
    std::string number;
    bool hasDot = false;
    
    while (position < length && (std::isdigit(currentChar()) || currentChar() == '.')) {
        if (currentChar() == '.') {
            if (hasDot) {
                throw std::runtime_error("无效的数字格式：多个小数点");
            }
            hasDot = true;
        }
        number += currentChar();
        advance();
    }
    
    return std::stod(number);
}

std::string Lexer::readIdentifier() {
    std::string identifier;
    while (position < length && (std::isalnum(currentChar()) || currentChar() == '_')) {
        identifier += currentChar();
        advance();
    }
    return identifier;
}

Token Lexer::getNextToken() {
    skipWhitespace();
    
    if (position >= length) {
        return Token(TokenType::END);
    }
    
    char ch = currentChar();
    
    // 处理数字
    if (std::isdigit(ch) || ch == '.') {
        double value = readNumber();
        return Token(TokenType::NUMBER, value, std::to_string(value));
    }
    
    // 处理标识符和函数名
    if (std::isalpha(ch)) {
        std::string identifier = readIdentifier();
        
        if (identifier == "sqrt") return Token(TokenType::SQRT, 0, identifier);
        if (identifier == "sin") return Token(TokenType::SIN, 0, identifier);
        if (identifier == "cos") return Token(TokenType::COS, 0, identifier);
        if (identifier == "tan") return Token(TokenType::TAN, 0, identifier);
        if (identifier == "log") return Token(TokenType::LOG, 0, identifier);
        if (identifier == "exp") return Token(TokenType::EXP, 0, identifier);
        
        return Token(TokenType::INVALID, 0, identifier);
    }
    
    // 处理操作符
    switch (ch) {
        case '+':
            advance();
            return Token(TokenType::PLUS, 0, "+");
        case '-':
            advance();
            return Token(TokenType::MINUS, 0, "-");
        case '*':
            advance();
            return Token(TokenType::MULTIPLY, 0, "*");
        case '/':
            advance();
            return Token(TokenType::DIVIDE, 0, "/");
        case '^':
            advance();
            return Token(TokenType::POWER, 0, "^");
        case '(':
            advance();
            return Token(TokenType::LEFT_PAREN, 0, "(");
        case ')':
            advance();
            return Token(TokenType::RIGHT_PAREN, 0, ")");
        default:
            advance();
            return Token(TokenType::INVALID, 0, std::string(1, ch));
    }
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    Token token = getNextToken();
    
    while (token.type != TokenType::END) {
        if (token.type == TokenType::INVALID) {
            throw std::runtime_error("无效字符：" + token.text);
        }
        tokens.push_back(token);
        token = getNextToken();
    }
    
    tokens.push_back(token); // 添加END令牌
    return tokens;
}
