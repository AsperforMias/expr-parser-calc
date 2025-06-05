#pragma once
#include <string>
#include <vector>

// 令牌类型枚举
enum class TokenType {
    NUMBER,       // 数字
    PLUS,         // +
    MINUS,        // -
    MULTIPLY,     // *
    DIVIDE,       // /
    POWER,        // ^
    LEFT_PAREN,   // (
    RIGHT_PAREN,  // )
    // 新增数学函数
    SQRT,         // sqrt
    SIN,          // sin
    COS,          // cos
    TAN,          // tan
    LOG,          // log
    EXP,          // exp
    END,          // 结束标记
    INVALID       // 无效令牌
};

// 令牌结构体
struct Token {
    TokenType type;
    double value;      // 对于数字令牌存储值
    std::string text;  // 原始文本
    
    Token(TokenType t, double v = 0.0, const std::string& txt = "")
        : type(t), value(v), text(txt) {}
};

// 词法分析器类
class Lexer {
private:
    std::string input;
    size_t position;
    size_t length;
    
    char currentChar();
    void advance();
    void skipWhitespace();
    double readNumber();
    std::string readIdentifier(); // 新增：读取标识符
    
public:
    Lexer(const std::string& input);
    Token getNextToken();
    std::vector<Token> tokenize();
};
