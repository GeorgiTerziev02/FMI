#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void readArray(std::vector<long>& arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

int main() {
    size_t firstArraySize, secondArraySize;
    std::cin >> firstArraySize >> secondArraySize;

    std::vector<long> firstArray(firstArraySize), secondArray(secondArraySize);

    readArray(firstArray, firstArraySize);
    readArray(secondArray, secondArraySize);

    std::sort(firstArray.begin(), firstArray.end());

    for (size_t i = 0; i < secondArraySize; i++) {
        auto index = std::lower_bound(firstArray.begin(), firstArray.end(), secondArray[i]);
        std::cout << index - firstArray.begin() << ' ';
    }

    return 0;
}