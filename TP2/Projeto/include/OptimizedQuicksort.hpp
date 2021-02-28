#ifndef OPT_QS_H
#define OPT_QS_H

#include "InsertionSort.hpp"
#include "Queue.hpp"
#include "siPair.hpp"

typedef struct {
    int left;
    int right;
} interval;

void OptPartition(int left, int right, int &i, int &j, siPair *vec) {
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
            j--;
        }

    } while (i <= j);
}

void OptimizedQuickSort(siPair *vec, int n) {

    Queue<interval> Q;
    int left = 0, right = n - 1, i, j;

    interval item;
    item.left = left;
    item.right = right;

    Q.insert(item);
    // Removes the overhead of multiple recursive calls
    do {
        if (right > left) {
            OptPartition(left, right, i, j, vec);
            if ((j - left) > (right - i)) {
                item.right = j;
                item.left = left;
                Q.insert(item);
                left = i;
            } else {
                item.left = i;
                item.right = right;
                Q.insert(item);
                right = j;
            }
        } else {
            item = Q.dequeue();
            right = item.right;
            left = item.left;
        }
    } while (!Q.isEmpty());
}

#endif