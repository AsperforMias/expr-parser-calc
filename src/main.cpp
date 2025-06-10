#include "calculator.h"
#include <iostream>
#include <string>

void printUsage(const char* program_name) {
    std::cout << "Usage: " << program_name << " [OPTIONS] [EXPRESSION]\n\n";
    std::cout << "Options:\n";
    std::cout << "  -h, --help     Show this help message\n";
    std::cout << "  -v, --version  Show version information\n";
    std::cout << "  -i, --interactive  Start interactive mode (default)\n";
    std::cout << "\nExamples:\n";
    std::cout << "  " << program_name << " \"2 + 3 * 4\"    # Calculate expression directly\n";
    std::cout << "  " << program_name << " -i             # Start interactive mode\n";
}

void printVersion() {
    std::cout << "Expression Calculator v1.0.0\n";
    std::cout << "Built with C++17\n";
}

int main(int argc, char* argv[]) {
    Calculator calculator;
    
    if (argc == 1) {
        // No arguments, start interactive mode
        calculator.run();
        return 0;
    }
    
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            printUsage(argv[0]);
            return 0;
        } else if (arg == "-v" || arg == "--version") {
            printVersion();
            return 0;
        } else if (arg == "-i" || arg == "--interactive") {
            calculator.run();
            return 0;
        } else {
            // Treat as expression to calculate
            try {
                double result = calculator.evaluate(arg);
                std::cout << "Result: " << result << std::endl;
                return 0;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return 1;
            }
        }
    }
    
    return 0;
}
