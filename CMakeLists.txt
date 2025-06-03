cmake_minimum_required(VERSION 3.10)
project(ExpressionCalculator VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加编译选项
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -O2)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4 /O2)
endif()

# 添加头文件目录
include_directories(include)

# 核心库
add_library(calculator_core STATIC
    src/lexer.cpp
    src/parser.cpp
    src/calculator.cpp
)

# 英文版可执行文件
add_executable(calculator_en
    src/main.cpp
    src/calculator_en.cpp
)
target_link_libraries(calculator_en calculator_core)

# 中文版可执行文件
add_executable(calculator_zh
    src/main.cpp
    src/calculator_zh.cpp
)
target_link_libraries(calculator_zh calculator_core)

# 默认可执行文件（基础版）
add_executable(calculator
    src/main.cpp
)
target_link_libraries(calculator calculator_core)

# 测试程序
add_executable(test_calculator
    test.cpp
)
target_link_libraries(test_calculator calculator_core)

# 编码测试程序
add_executable(test_encoding
    test_encoding.cpp
)

# 设置输出目录
set_target_properties(calculator_en calculator_zh calculator test_calculator test_encoding PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
