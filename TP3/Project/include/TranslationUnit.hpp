#ifndef TRANSLATION_UNIT
#define TRANSLATION_UNIT

#include "BinarySearchTree.hpp"
#include <string>

template <class T>
class TranslationUnit {

    std::string tree_str;
    BinarySearchTree<T> tree;

public:
    TranslationUnit() {};

    void buildTreeFromString(std::string s);
    std::string decodeMessage(std::string s);
    std::string encodeMessage(std::string s);
};

#endif