#ifndef TRANSLATION_UNIT
#define TRANSLATION_UNIT

#include "BinarySearchTree.hpp"
#include "stdlib.h"
#include "time.h"
#include <string>

template <class T>
class TranslationUnit {

    std::string tree_str;
    BinarySearchTree<T> tree;
    void decodingSearchFromStringProcedure(std::stringstream &decodingStream, std::string s);
    int generateRandomNumber(bool even = true);

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
        this->decodingSearchFromStringProcedure(decoded, str);
    }

    str = message;
    this->decodingSearchFromStringProcedure(decoded, str);

    return decoded.str();
}

template <class T>
std::string TranslationUnit<T>::encodeMessage(std::string message) {
    std::stringstream encoded;

    for (auto &letter : message) {
        encoded << 'x';
        std::string path = this->tree.pathOf(letter);
        for (auto &pathLetter : path) {
            if (pathLetter == 'L')
                encoded << generateRandomNumber(false);
            else if (pathLetter == 'R')
                encoded << generateRandomNumber();
        }
    }

    return encoded.str();
}

template <class T>
T TranslationUnit<T>::searchByPath(int num) {
    return this->tree.search(num);
}

template <class T>
void TranslationUnit<T>::decodingSearchFromStringProcedure(std::stringstream &decodingStream, std::string s) {
    if (s != "") {
        if (s[0] == '0')
            s[0] = '2'; // when converting to int the char '0' is removed
        decodingStream << this->searchByPath(std::stoi(s));
    } else
        decodingStream << this->tree_str[0];
}

template <class T>
int TranslationUnit<T>::generateRandomNumber(bool even) {
    bool goodToGo = false;
    int num = -1;

    while (!goodToGo) {
        num = rand() % 10;
        if (even) {
            if (num % 2 == 0)
                goodToGo = true;
        } else {
            if (num % 2 != 0)
                goodToGo = true;
        }
    }
    return num;
}

#endif