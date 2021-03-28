#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/TranslationUnit.hpp"

int main(int argc, char *argv[]) {

    if (!argv[1]) {
        std::cout << "Argumentos invalidos" << std::endl;
        exit(-1);
    }

    srand(time(NULL));

    std::string fileName = std::string(argv[1]);

    TranslationUnit<char> transUnit;

    std::string commandContent = "";
    char commandType = ' ';

    std::fstream f(fileName);

    while (std::getline(f, commandContent)) {
        commandType = commandContent[0];
        commandContent.erase(0, 3);
        if (commandType == 'A') {
            transUnit.buildTreeFromString(commandContent);
        } else if (commandType == 'C') {
            std::string encodedMsg = transUnit.encodeMessage(commandContent);
            std::cout << encodedMsg << std::endl;
        } else if (commandType == 'D') {
            std::string decodedMsg = transUnit.decodeMessage(commandContent);
            std::cout << decodedMsg << std::endl;
        }
    }
}