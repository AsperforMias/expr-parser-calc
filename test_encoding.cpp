#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#endif

void testEncodingMethod1() {
    std::cout << "\n=== Method 1: Default Console Output ===" << std::endl;
    std::cout << "中文测试：欢迎使用表达式计算器" << std::endl;
    std::cout << "English test: Welcome to Expression Calculator" << std::endl;
}

void testEncodingMethod2() {
    std::cout << "\n=== Method 2: UTF-8 Console Output ===" << std::endl;
    
#ifdef _WIN32
    // 设置控制台代码页为UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    
    std::cout << "中文测试：欢迎使用表达式计算器" << std::endl;
    std::cout << "English test: Welcome to Expression Calculator" << std::endl;
}

void testEncodingMethod3() {
    std::cout << "\n=== Method 3: GBK Console Output ===" << std::endl;
    
#ifdef _WIN32
    // 设置控制台代码页为GBK
    SetConsoleOutputCP(936);
    SetConsoleCP(936);
#endif
    
    std::cout << "中文测试：欢迎使用表达式计算器" << std::endl;
    std::cout << "English test: Welcome to Expression Calculator" << std::endl;
}

void testEncodingMethod4() {
    std::cout << "\n=== Method 4: Wide Character Output ===" << std::endl;
    
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"中文测试：欢迎使用表达式计算器" << std::endl;
    std::wcout << L"English test: Welcome to Expression Calculator" << std::endl;
    _setmode(_fileno(stdout), _O_TEXT);
#else
    std::cout << "Wide character test (Linux/Mac):" << std::endl;
    std::cout << "中文测试：欢迎使用表达式计算器" << std::endl;
    std::cout << "English test: Welcome to Expression Calculator" << std::endl;
#endif
}

int main() {
    std::cout << "Testing Chinese Character Display Support" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    testEncodingMethod1();
    testEncodingMethod2();
    testEncodingMethod3();
    testEncodingMethod4();
    
    std::cout << "\n=== Summary ===" << std::endl;
    std::cout << "Please check which method displays Chinese characters correctly." << std::endl;
    std::cout << "The method that shows '欢迎使用表达式计算器' properly is the best one." << std::endl;
    
    return 0;
}
