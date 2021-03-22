#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


int main(int argc, char *argv[]) {

    std::string fileName = std::string(argv[1]);

    std::string currentCommand = "";

    std::fstream f(fileName);
    while (f >> currentCommand) {
        if (currentCommand[0] == 'A') {
            // Montar Arvore

        } else if (currentCommand[0] == 'C') {
            // Codificar entrada

        } else if (currentCommand[0] == 'D') {
            // Decodificar entrada

        } else {
            std::cout << "Tipo de Comando INVALIDO" << std::endl;
        }
    }
}