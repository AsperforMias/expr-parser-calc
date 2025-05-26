cmake_minimum_required(VERSION 3.10)
project(ExpressionCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加头文件目录
include_directories(include)

# 创建可执行文件
add_executable(calculator
    src/main.cpp
    src/lexer.cpp
    src/parser.cpp
    src/calculator.cpp
)

# 创建测试程序
add_executable(test_calculator
    test.cpp
    src/lexer.cpp
    src/parser.cpp
    src/calculator.cpp
)

# 设置输出目录
set_target_properties(calculator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_target_properties(test_calculator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
