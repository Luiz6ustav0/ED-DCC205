// #include "Test.h"
#include "../include/GnomeSort.hpp"
#include "../include/HeapSort.hpp"
#include "../include/InsertionSort.hpp"
#include "../include/OptimizedQuicksort.hpp"
#include "../include/QuickSort.hpp"

#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {

    if (!argv[1] || !argv[2]) {
        std::cout << "Argumentos invalidos" << std::endl;
        exit(-1);
    }

    std::string fileName = argv[1], tempPlanetName = "";
    int linhas = std::stoi(argv[2]), tempHyperjumps = 0;

    std::fstream arqLeitura(fileName);
    siPair temp;

    /*** Insertion e Quick Sort ***/

    siPair *myVec = new siPair[linhas];

    for (int i = 0; i < linhas; ++i) {
        arqLeitura >> tempPlanetName >> tempHyperjumps;
        temp.first = tempPlanetName;
        temp.second = tempHyperjumps;
        myVec[i] = temp;
    }

    /* ESCOLHA O METODO AQUI */
    // gnomeSort(myVec, linhas);
    // insertionSort(myVec, linhas);
    // QuickSort(myVec, linhas);
    OptimizedQuickSort(myVec, linhas);

    if (linhas > 7)
        linhas = 7;
    for (int i = 0; i < linhas; ++i)
        std::cout << myVec[i].first << " " << myVec[i].second << std::endl;

    /*** *** ***/

    /*** Heapsort ***/

    // temp.first = "First Item";
    // temp.second = -303;
    // siPair *myVec = new siPair[linhas + 1];
    // myVec[0] = temp;
    // int count = 1;
    // for (int i = 1; i <= linhas; ++i) {
    //     arqLeitura >> tempPlanetName >> tempHyperjumps;
    //     temp.first = tempPlanetName;
    //     temp.second = tempHyperjumps;
    //     myVec[count] = temp;
    //     count++;
    // }

    // HeapSort(myVec, linhas);

    // if (linhas > 7)
    //     linhas = 7;
    // for (int i = 1; i <= linhas; ++i)
    //     std::cout << myVec[i].first << " " << myVec[i].second << std::endl;

    /*** *** ***/

    delete[] myVec;
}