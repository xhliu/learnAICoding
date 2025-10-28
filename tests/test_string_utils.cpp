#include <cassert>
#include <iostream>
#include <vector>
#include "../include/string_utils.h"

void test_toUpper() {
    assert(StringUtils::toUpper("hello") == "HELLO");
    assert(StringUtils::toUpper("Hello World!") == "HELLO WORLD!");
    assert(StringUtils::toUpper("") == "");
    assert(StringUtils::toUpper("123abc") == "123ABC");
    std::cout << "✓ toUpper tests passed\n";
}

void test_toLower() {
    assert(StringUtils::toLower("HELLO") == "hello");
    assert(StringUtils::toLower("Hello World!") == "hello world!");
    assert(StringUtils::toLower("") == "");
    assert(StringUtils::toLower("123ABC") == "123abc");
    std::cout << "✓ toLower tests passed\n";
}

void test_split() {
    std::vector<std::string> result;

    result = StringUtils::split("apple,banana,cherry", ',');
    assert(result.size() == 3);
    assert(result[0] == "apple");
    assert(result[1] == "banana");
    assert(result[2] == "cherry");

    result = StringUtils::split("one", ',');
    assert(result.size() == 1);
    assert(result[0] == "one");

    result = StringUtils::split("", ',');
    assert(result.size() == 0);

    result = StringUtils::split("a,,b", ',');
    assert(result.size() == 2); // Empty tokens are filtered
    assert(result[0] == "a");
    assert(result[1] == "b");

    std::cout << "✓ split tests passed\n";
}

void test_trim() {
    assert(StringUtils::trim("  hello  ") == "hello");
    assert(StringUtils::trim("hello") == "hello");
    assert(StringUtils::trim("   ") == "");
    assert(StringUtils::trim("") == "");
    assert(StringUtils::trim("  leading") == "leading");
    assert(StringUtils::trim("trailing  ") == "trailing");
    std::cout << "✓ trim tests passed\n";
}

int main() {
    std::cout << "Running String Utils Tests...\n\n";

    try {
        test_toUpper();
        test_toLower();
        test_split();
        test_trim();

        std::cout << "\n✓ All tests passed!\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "✗ Test failed: " << e.what() << "\n";
        return 1;
    }
}
