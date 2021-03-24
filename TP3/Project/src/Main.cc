#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/BinarySearchTree.hpp"

int main(int argc, char *argv[]) {

    BinarySearchTree<char> bst;
    bst.insert('A');
    bst.insert('B');
    std::cout << bst.search() << std::endl; 
    
    
    // std::string fileName = std::string(argv[1]);

    // std::string currentCommand = "";

    // std::fstream f(fileName);
    // while (f >> currentCommand) {
    //     if (currentCommand[0] == 'A') {
    //         // Montar Arvore

    //     } else if (currentCommand[0] == 'C') {
    //         // Codificar entrada

    //     } else if (currentCommand[0] == 'D') {
    //         // Decodificar entrada

    //     } else {
    //         std::cout << "Tipo de Comando INVALIDO" << std::endl;
    //     }
    // }
}