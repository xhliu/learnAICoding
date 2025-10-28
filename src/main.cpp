#include <iostream>
#include <vector>
#include "string_utils.h"

int main() {
    std::cout << "C++ Sample Project - String Utilities Demo\n";
    std::cout << "==========================================\n\n";

    // Test toUpper
    std::string testStr = "Hello, World!";
    std::cout << "Original: " << testStr << "\n";
    std::cout << "Upper: " << StringUtils::toUpper(testStr) << "\n";
    std::cout << "Lower: " << StringUtils::toLower(testStr) << "\n\n";

    // Test split
    std::string csvStr = "apple,banana,cherry,date";
    std::cout << "Splitting: " << csvStr << "\n";
    std::vector<std::string> tokens = StringUtils::split(csvStr, ',');
    std::cout << "Tokens:\n";
    for (const auto& token : tokens) {
        std::cout << "  - " << token << "\n";
    }
    std::cout << "\n";

    // Test trim
    std::string spacedStr = "   Hello World   ";
    std::cout << "Original with spaces: '" << spacedStr << "'\n";
    std::cout << "Trimmed: '" << StringUtils::trim(spacedStr) << "'\n\n";

    std::cout << "Demo completed successfully!\n";

    return 0;
}
