# Expression Parser Calculator

[![Language](https://img.shields.io/badge/language-C%2B%2B17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)](#compilation-and-build)

> [中文文档](README-zh.md)

A mathematical expression parser and calculator implemented in modern C++17, featuring basic arithmetic operations, operator precedence, and comprehensive error handling.

## Features

- Basic arithmetic operations: `+`, `-`, `*`, `/`
- Exponentiation: `^` (right-associative)
- Parentheses for grouping: `()`
- Unary operators: `+`, `-`
- Floating-point number support
- Comprehensive error handling (syntax errors, division by zero, etc.)
- Interactive command-line interface
- Cross-platform support (Windows, Linux, macOS)
- Localized interface (English and Chinese versions)

## Quick Start

### Download and Build

```bash
# Clone the repository
git clone https://github.com/yourusername/expr-parser-calc.git
cd expr-parser-calc

# Compile the program
g++ -std=c++17 -I include src/*.cpp -o calculator

# Run the program
./calculator
```

### Usage Examples

```
Calculator> 2 + 3 * 4
Result: 14

Calculator> (2 + 3) * 4  
Result: 20

Calculator> 2^3 + 1
Result: 9

Calculator> -5 + 3.14
Result: -1.86
```

## Project Structure

```
expr-parser-calc/
├── CMakeLists.txt          # CMake build configuration
├── include/                # Header files
│   ├── lexer.h            # Lexer interface
│   ├── parser.h           # Parser interface  
│   └── calculator.h       # Calculator interface
├── src/                   # Source files
│   ├── main.cpp           # Program entry point
│   ├── lexer.cpp          # Lexer implementation
│   ├── parser.cpp         # Parser implementation
│   ├── calculator.cpp     # Calculator implementation (original)
│   ├── calculator_en.cpp  # English version
│   └── calculator_zh.cpp  # Chinese version
├── test.cpp               # Unit tests
├── test_encoding.cpp      # Encoding tests
├── .gitignore             # Git ignore file
├── LICENSE                # MIT license
└── README.md              # Project documentation
```

## Compilation and Build

### Method 1: Using CMake (Recommended)

```bash
# Create build directory
mkdir build && cd build

# Generate build files
cmake ..

# Build the project
cmake --build .

# Run the program
./bin/calculator    # Linux/macOS
./bin/calculator.exe    # Windows
```

### Method 2: Direct Compilation

**Windows (PowerShell):**
```powershell
# Compile Chinese version
g++ -std=c++17 -I include src/main.cpp src/lexer.cpp src/parser.cpp src/calculator_zh.cpp -o calculator_zh.exe

# Compile English version
g++ -std=c++17 -I include src/main.cpp src/lexer.cpp src/parser.cpp src/calculator_en.cpp -o calculator_en.exe

# Run tests
g++ -std=c++17 -I include test.cpp src/lexer.cpp src/parser.cpp src/calculator.cpp -o test.exe
.\test.exe
```

**Linux/macOS:**
```bash
# Compile Chinese version
g++ -std=c++17 -I include src/main.cpp src/lexer.cpp src/parser.cpp src/calculator_zh.cpp -o calculator_zh

# Compile English version  
g++ -std=c++17 -I include src/main.cpp src/lexer.cpp src/parser.cpp src/calculator_en.cpp -o calculator_en

# Run tests
g++ -std=c++17 -I include test.cpp src/lexer.cpp src/parser.cpp src/calculator.cpp -o test
./test
```

### Requirements

- **Compiler**: C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- **CMake**: 3.10+ (optional)
- **OS**: Windows 10+, Linux, macOS

## 使用说明

启动程序后，您可以：

1. 输入数学表达式进行计算
2. 输入 `help` 查看帮助信息
3. 输入 `quit` 或 `exit` 退出程序

### 示例表达式

```
计算器> 2 + 3 * 4
结果: 14

计算器> (2 + 3) * 4
结果: 20

计算器> 2^3 + 1
结果: 9

计算器> -5 + 3
结果: -2

计算器> (3 + 4) * (2 - 1)
结果: 7
```

## Technical Implementation

### Lexer (Lexical Analyzer)
- Converts input strings into token sequences
- Recognizes numbers, operators, and parentheses
- Handles whitespace and floating-point numbers
- Comprehensive error detection and reporting

### Parser (Syntax Analyzer)  
- Recursive descent parsing algorithm
- Constructs Abstract Syntax Tree (AST)
- Proper operator precedence and associativity handling
- Supports nested parentheses and complex expressions

### Calculator (Evaluation Engine)
- Traverses AST to evaluate expressions
- Complete exception handling mechanism
- Supports both interactive and batch processing modes
- Cross-platform encoding support

## Operator Precedence

| Precedence | Operators | Associativity | Description |
|------------|-----------|---------------|-------------|
| 1 (Highest) | `()` | - | Parentheses |  
| 2 | `+`, `-` (unary) | Right | Unary plus/minus |
| 3 | `^` | Right | Exponentiation |
| 4 | `*`, `/` | Left | Multiplication/Division |
| 5 (Lowest) | `+`, `-` | Left | Addition/Subtraction |

## Test Cases

The project includes a comprehensive test suite covering:

```cpp
// Basic arithmetic
"2 + 3" → 5.0
"2 + 3 * 4" → 14.0  // Multiplication has higher precedence

// Parentheses grouping  
"(2 + 3) * 4" → 20.0

// Exponentiation
"2^3" → 8.0
"2^3 + 1" → 9.0

// Unary operators
"-5 + 3" → -2.0

// Floating-point arithmetic
"3.14 * 2" → 6.28

// Complex expressions
"(3 + 4) * (2 - 1)" → 7.0
```

Run tests:
```bash
./test    # View all test results
```

## Error Handling

The program detects and reports the following errors:
- Invalid characters
- Syntax errors
- Division by zero
- Number format errors
- Mismatched parentheses

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Issues and pull requests are welcome!

## Author

[AsperforMias](https://github.com/AsperforMias)
