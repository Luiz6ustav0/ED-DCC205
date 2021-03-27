#include "../include/TranslationUnit.hpp"

std::unordered_map<char, int> alphabetMap = {
    {' ', -1}, {'A', 1}, {'B', 2}, {'C', 3}, {'D', 4},
    {'E', 5}, {'F', 6}, {'G', 7}, {'H', 8}, {'I', 9},
    {'J', 10}, {'K', 11}, {'L', 12}, {'M', 13}, {'N', 14},
    {'O', 15}, {'P', 16}, {'Q', 17}, {'R', 18}, {'S', 19},
    {'T', 20}, {'U', 21}, {'V', 22}, {'W', 23}, {'X', 24},
    {'Y', 25}, {'Z', 26}
};

template <class T>
void TranslationUnit<T>::buildTreeFromString(std::string lex) {
    std::ostringstream s;
    s << lex;
    std::string str = s.str();
    this->tree_str = lex;

    for (auto i : str) {
        this->tree.insert(i);
        // std::cout << i << " inserted" << std::endl;
    }
}

template <class T>
std::string TranslationUnit<T>::decodeMessage(std::string message) {
    return "hi";
}

template <class T>
std::string TranslationUnit<T>::encodeMessage(std::string message) {
    return "hello";
}
