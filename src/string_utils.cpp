#include "string_utils.h"
#include <algorithm>
#include <sstream>
#include <cctype>

namespace StringUtils {

std::string toUpper(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}

std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    return tokens;
}

std::string trim(const std::string& str) {
    auto start = std::find_if(str.begin(), str.end(),
                              [](unsigned char ch) { return !std::isspace(ch); });
    auto end = std::find_if(str.rbegin(), str.rend(),
                            [](unsigned char ch) { return !std::isspace(ch); }).base();

    return (start < end) ? std::string(start, end) : std::string();
}

}
