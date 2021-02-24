#include <vector>
#include <string>

void insertionSort(std::vector<std::pair<std::string, int>> &vec)
{
    int vecSize = vec.size();

    for (int i = 1; i < vecSize; ++i)
    {
        std::pair<std::string, int> valueToInsert = vec[i];
        int pos = i;

        while (pos > 0 && vec[pos - 1].second < valueToInsert.second)
        {
            vec[pos] = vec[pos - 1];
            pos -= 1;
        }
        vec[pos] = valueToInsert;
    }
}