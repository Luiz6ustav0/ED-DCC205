#ifndef TRANSLATION_UNIT
#define TRANSLATION_UNIT

#include "BinarySearchTree.hpp"
#include <string>

std::unordered_map<char, int> alphabetMap = {
    {' ', -1}, {'A', 1}, {'B', 2}, {'C', 3}, 
    {'D', 4}, {'E', 5}, {'F', 6}, {'G', 7}, 
    {'H', 8}, {'I', 9}, {'J', 10}, {'K', 11}, 
    {'L', 12}, {'M', 13}, {'N', 14}, {'O', 15}, 
    {'P', 16}, {'Q', 17}, {'R', 18}, {'S', 19}, 
    {'T', 20}, {'U', 21}, {'V', 22}, {'W', 23}, 
    {'X', 24}, {'Y', 25}, {'Z', 26}
};

template <class T>
class TranslationUnit {

    std::string tree_str;
    BinarySearchTree<T> tree;
    void decodingSearchProcedure(std::stringstream &decodingStream, std::string s);

public:
    TranslationUnit(){};

    void buildTreeFromString(std::string s);
    std::string decodeMessage(std::string s);
    std::string encodeMessage(std::string s);
    T searchByPath(int n);
};

template <class T>
void TranslationUnit<T>::buildTreeFromString(std::string lex) {
    std::ostringstream s;
    s << lex;
    std::string str = s.str();
    this->tree_str = lex;

    for (auto i : str)
        this->tree.insert(i);
}

template <class T>
std::string TranslationUnit<T>::decodeMessage(std::string message) {
    std::stringstream decoded;
    std::string str = "";

    char delimiter('x');
    int pos = 0;

    message.erase(0, 1); // removing first 'x'

    while ((pos = message.find(delimiter)) != std::string::npos) {
        str = message.substr(0, pos);
        message.erase(0, pos + 1);
        this->decodingSearchProcedure(decoded, str);
    }

    str = message;
    this->decodingSearchProcedure(decoded, str);

    return decoded.str();
}

template <class T>
std::string TranslationUnit<T>::encodeMessage(std::string message) {
    return " ";
}

template <class T>
T TranslationUnit<T>::searchByPath(int num) {
    return this->tree.search(num);
}

template <class T>
void TranslationUnit<T>::decodingSearchProcedure(std::stringstream &decodingStream, std::string s) {
    if (s != "") {
        if (s[0] == '0')
            s[0] = '2'; // when converting to int the char '0' is removed
        decodingStream << this->tree.search(std::stoi(s));
    } else
        decodingStream << this->tree_str[0];
}


#endif