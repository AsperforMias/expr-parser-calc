# 表达式解析器计算器

一个使用现代 C++17 实现的数学表达式解析器和计算器，支持基本数学运算、括号优先级和完整的错误处理。

## 功能特性

- 基本四则运算：`+` (加法)、`-` (减法)、`*` (乘法)、`/` (除法)
- 乘方运算：`^` (支持右结合)
- 括号优先级：`()`
- 一元运算符：`+`、`-`
- 浮点数支持：完整的小数运算
- 详细错误处理：语法错误、除零错误等
- 交互式界面：友好的命令行交互
- 跨平台支持：Windows、Linux、macOS
- 中文界面：支持中文提示信息

## 快速开始

### 下载和编译

```bash
# 克隆仓库
git clone https://github.com/yourusername/expr-parser-calc.git
cd expr-parser-calc

# 编译程序
g++ -std=c++17 -I include src/*.cpp -o calculator

# 运行程序
./calculator
```

### 使用示例

```
计算器> 2 + 3 * 4
结果: 14

计算器> (2 + 3) * 4  
结果: 20

计算器> 2^3 + 1
结果: 9

计算器> -5 + 3.14
结果: -1.86
```

## 项目结构

```
expr-parser-calc/
├── CMakeLists.txt          # CMake 构建配置
├── include/                # 头文件目录
│   ├── lexer.h            # 词法分析器接口
│   ├── parser.h           # 语法分析器接口  
│   └── calculator.h       # 计算器接口
├── src/                   # 源代码目录
│   ├── main.cpp           # 程序入口点
│   ├── lexer.cpp          # 词法分析器实现
│   ├── parser.cpp         # 语法分析器实现
│   ├── calculator.cpp     # 计算器实现 (原版)
│   ├── calculator_en.cpp  # 英文版本
│   └── calculator_zh.cpp  # 中文版本
├── test.cpp               # 单元测试
├── test_encoding.cpp      # 编码测试
├── .gitignore             # Git 忽略文件
├── LICENSE                # MIT 开源协议
└── README.md              # 项目文档
```

## 编译和运行

### 方法 1：使用 CMake (推荐)

```bash
# 创建构建目录
mkdir build && cd build

# 生成构建文件
cmake ..

# 编译项目
cmake --build .

# 运行程序
./bin/calculator    # Linux/macOS
./bin/calculator.exe    # Windows
```

### 方法 2：直接编译

**Windows (PowerShell):**
```powershell
# 编译中文版
g++ -std=c++17 -I include src/main.cpp src/lexer.cpp src/parser.cpp src/calculator_zh.cpp -o calculator_zh.exe

# 编译英文版
g++ -std=c++17 -I include src/main.cpp src/lexer.cpp src/parser.cpp src/calculator_en.cpp -o calculator_en.exe

# 运行测试
g++ -std=c++17 -I include test.cpp src/lexer.cpp src/parser.cpp src/calculator.cpp -o test.exe
.\test.exe
```

**Linux/macOS:**
```bash
# 编译中文版
g++ -std=c++17 -I include src/main.cpp src/lexer.cpp src/parser.cpp src/calculator_zh.cpp -o calculator_zh

# 编译英文版  
g++ -std=c++17 -I include src/main.cpp src/lexer.cpp src/parser.cpp src/calculator_en.cpp -o calculator_en

# 运行测试
g++ -std=c++17 -I include test.cpp src/lexer.cpp src/parser.cpp src/calculator.cpp -o test
./test
```

### 系统要求

- **编译器**: 支持 C++17 的编译器 (GCC 7+, Clang 5+, MSVC 2017+)
- **CMake**: 3.10+ (可选)
- **操作系统**: Windows 10+, Linux, macOS

## 技术实现

### 词法分析器 (Lexer)
- 将输入字符串转换为令牌序列
- 识别数字、操作符和括号
- 处理空白字符和浮点数
- 完整的错误检测和报告

### 语法分析器 (Parser)  
- 基于递归下降的解析算法
- 构建抽象语法树 (AST)
- 正确处理运算符优先级和结合性
- 支持嵌套括号和复杂表达式

### 计算引擎 (Calculator)
- 遍历 AST 进行表达式求值
- 完整的异常处理机制
- 支持交互式和批处理模式
- 跨平台的编码支持

## 运算符优先级

| 优先级 | 运算符 | 结合性 | 说明 |
|--------|--------|--------|------|
| 1 (最高) | `()` | - | 括号 |  
| 2 | `+`, `-` (一元) | 右结合 | 正负号 |
| 3 | `^` | 右结合 | 乘方 |
| 4 | `*`, `/` | 左结合 | 乘除 |
| 5 (最低) | `+`, `-` | 左结合 | 加减 |

## 测试用例

项目包含完整的测试套件，覆盖以下场景：

```cpp
// 基本运算
"2 + 3" → 5.0
"2 + 3 * 4" → 14.0  // 乘法优先级高于加法

// 括号优先级  
"(2 + 3) * 4" → 20.0

// 乘方运算
"2^3" → 8.0
"2^3 + 1" → 9.0

// 一元运算符
"-5 + 3" → -2.0

// 浮点数运算
"3.14 * 2" → 6.28

// 复杂表达式
"(3 + 4) * (2 - 1)" → 7.0
```

运行测试：
```bash
./test    # 查看所有测试结果
```

## 错误处理

程序会检测并报告以下错误：
- 无效字符
- 语法错误
- 除零错误
- 数字格式错误
- 括号不匹配

## 许可证

本项目基于 MIT 许可证开源 - 查看 [LICENSE](LICENSE) 文件了解详情。

## 贡献

欢迎提交 Issue 和 Pull Request！

## 作者

[AsperforMias](https://github.com/AsperforMias)
