#ifndef SHELL_S
#define SHELL_S

#include "siPair.hpp"

void ShellSort(siPair *vec, int n) {
    int inner_i;
    for (int window = n / 2; window > 0; window /= 2) {
        for (int i = window; i < n; i++) {
            siPair temp = vec[i];
            for (inner_i = i; inner_i >= window && temp.second < vec[inner_i - window].second; inner_i -= window) {
                vec[inner_i] = vec[inner_i - window];
            }
            vec[inner_i] = temp;
        }
    }
}

#endif