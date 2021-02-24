#include <string>
#include <vector>

void recreateHeapCondition(int L, int R, std::vector<std::pair<std::string, int>> vec) {
    int i, j;
    std::pair<std::string, int> item;
    i = L;
    j = i * 2;
    item = vec[i];
    while (j <= R) {
        if (j < R)
            if (vec[j].second < vec[j + 1].second)
                j++;
        if (item.second >= vec[j].second)
            break;
        vec[i] = vec[j];
        i = j;
        j = i * 2;
    }
    vec[i] = item;
}

void buildHeap(std::vector<std::pair<std::string, int>> vec, int size = -1) {
    if (size == -1)
        size = vec.size();
    int left;
    left = (size / 2) + 1;
    while (left > 1) {
        left--;
        recreateHeapCondition(left, size, vec);
    }
}

void HeapSort(std::vector<std::pair<std::string, int>> &vec) {
    int left, right;
    std::pair<std::string, int> tempPair;
    buildHeap(vec);
    left = 1;
    right = vec.size();
    while (right > 1) {
        tempPair = vec[1];
        vec[1] = vec[right];
        vec[right] = tempPair;
        right--;
        recreateHeapCondition(left, right, vec);
    }
}