#include <iostream>

unsigned long nearestCube(unsigned long n) {
    unsigned long start = 1;

    while (start * start * start <= n) {
        start++;
    }
    start--;

    return start * start * start;
}

int task1_2021() {
    unsigned long n;
    std::cin >> n;
    unsigned counter = 0;

    while (n != 0) {
        n -= nearestCube(n);
        counter++;
    }

    std::cout << counter;

    return 0;
}
