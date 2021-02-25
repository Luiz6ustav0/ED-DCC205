#include <string>
#include <vector>
#include "siPair.hpp"

void Partition(int left, int right, int &i, int &j, siPair *vec) {
    siPair pivot, temp;
    i = left;
    j = right;
    pivot = vec[(i + j) / 2];
    do {
        while (pivot.second < vec[i].second)
            i++;
        while (pivot.second > vec[j].second)
            j--;
        if (i <= j) {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j++;
        }

    } while (i <= j);
}

void order(int left, int right, siPair *vec) {
    int i, j;
    Partition(left, right, i, j, vec);
    if (left < j)
        order(left, j, vec);
    if (i < right)
        order(i, right, vec);
}

void QuickSort(siPair *vec, int n) {
    order(0, n - 1, vec);
}