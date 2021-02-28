#ifndef GNOME_S_H
#define GNOME_S_H

#include "siPair.hpp"

void gnomeSort(siPair *vec, int n) {
    int currentPos = 0;
    while (currentPos < n) {
        if (currentPos == 0)
            currentPos++;
        if (vec[currentPos].second < vec[currentPos - 1].second)
            currentPos++;
        else {
            std::swap(vec[currentPos], vec[currentPos - 1]);
            currentPos--;
        }
    }
}

#endif