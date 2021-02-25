#include "siPair.hpp"

void recreateHeapCondition(int L, int R, siPair *vec) {
    int i, j;
    siPair item;
    i = L;
    j = i * 2;
    item = vec[i];
    while (j <= R) {
        if (j < R)
            if (vec[j].second > vec[j + 1].second)
                j++;
        if (item.second < vec[j].second)
            break;
        vec[i] = vec[j];
        i = j;
        j = i * 2;
    }
    vec[i] = item;
}

void buildHeap(siPair *vec, int size) {
    int left = size / 2 + 1;
    while (left > 1) {
        left--;
        recreateHeapCondition(left, size, vec);
    }
}

void HeapSort(siPair *vec, int &n) {
    int left, right;
    siPair tempPair;
    buildHeap(vec, n);
    left = 1; right = n;
    while (right > 1) {
        tempPair = vec[1];
        vec[1] = vec[right];
        vec[right] = tempPair;
        right--;
        recreateHeapCondition(left, right, vec);
    }
}