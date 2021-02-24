// #include "Test.h"
#include "../include/HeapSort.hpp"
#include "../include/InsertionSort.hpp"
#include "../include/QuickSort.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> myVec;
    for (int i = 0; i <= 10; ++i) {
        std::pair<std::string, int> temp(std::to_string(i), i + 3);
        myVec.push_back(temp);
    }
    for (auto &i : myVec)
        std::cout << i.second << " ";
    std::cout << std::endl;
    // insertionSort(myVec);
    // QuickSort(myVec);
    HeapSort(myVec);
    for (auto &i : myVec)
        std::cout << i.second << " ";
}