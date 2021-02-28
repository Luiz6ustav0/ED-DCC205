#ifndef INSERT_S_H
#define INSERT_S_H

#include "siPair.hpp"

void insertionSort(siPair *vec, int n) {
    int vecSize = n;

    for (int i = 1; i < vecSize; ++i) {
        siPair valueToInsert = vec[i];
        int pos = i;

        while (pos > 0 && vec[pos - 1].second < valueToInsert.second) {
            vec[pos] = vec[pos - 1];
            pos -= 1;
        }
        vec[pos] = valueToInsert;
    }
}

#endif