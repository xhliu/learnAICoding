#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

namespace StringUtils {
    /**
     * Converts a string to uppercase
     * @param str Input string
     * @return Uppercase version of the string
     */
    std::string toUpper(const std::string& str);

    /**
     * Converts a string to lowercase
     * @param str Input string
     * @return Lowercase version of the string
     */
    std::string toLower(const std::string& str);

    /**
     * Splits a string by a delimiter
     * @param str Input string
     * @param delimiter Character to split on
     * @return Vector of string tokens
     */
    std::vector<std::string> split(const std::string& str, char delimiter);

    /**
     * Trims whitespace from both ends of a string
     * @param str Input string
     * @return Trimmed string
     */
    std::string trim(const std::string& str);
}

#endif // STRING_UTILS_H
