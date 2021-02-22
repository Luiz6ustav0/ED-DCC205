#include <vector>
#include <string>

#define siPair std::pair<std::string, int>

void insertionSort(std::vector<siPair> &vec)
{
    int vecSize = vec.size();

    for (int i = 1; i < vecSize; ++i)
    {
        siPair valueToInsert = vec[i];
        int pos = i;

        while (pos > 0 && vec[pos-1].second > valueToInsert.second) {
            vec[pos] = vec[pos-1];
            pos -= 1;
        }
        vec[pos] = valueToInsert;
    }
}