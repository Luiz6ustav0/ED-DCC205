#ifndef TRANSLATION_UNIT
#define TRANSLATION_UNIT

#include <string>

class TranslationUnit {

    std::string tree_str;
    char *treevec;

public:
    TranslationUnit(std::string t = "");
    ~TranslationUnit();

    void buildTreeFromString(std::string t);
    std::string decodeMessage(std::string s);
    std::string encodeMessage(std::string s);
};

#endif