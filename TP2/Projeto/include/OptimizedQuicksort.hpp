#ifndef OPT_QS_H
#define OPT_QS_H

#include "InsertionSort.hpp"
#include "Queue.hpp"
#include "siPair.hpp"
#include "stdlib.h"
#include "time.h"

typedef struct {
    int left;
    int right;
} interval;

int Median(int a, int b, int c) {
    if (a < b) {
        if (b < c)
            return b;
        if (a < c)
            return c;
        return a;
    }
    if (a < c)
        return a;
    if (b < c)
        return c;
    return b;
}

int Pivot(siPair *vec, int low, int high) {
    int index1 = rand() % (high - low);
    int index2 = rand() % (high - low);
    int index3 = rand() % (high - low);
    return Median(vec[low + index1].second, vec[low + index2].second, vec[low + index3].second);
}

void OptPartition(int left, int right, int &i, int &j, siPair *vec) {
    siPair temp;
    i = left;
    j = right;
    int pivot = Pivot(vec, i, j);
    do {
        while (pivot < vec[i].second)
            i++;
        while (pivot > vec[j].second)
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
    srand(time(NULL));
    Queue<interval> Q;
    int left = 0, right = n - 1, i, j;

    interval item;
    item.left = left;
    item.right = right;

    Q.insert(item);
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