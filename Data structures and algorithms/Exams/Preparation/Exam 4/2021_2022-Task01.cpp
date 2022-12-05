#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Order {
    size_t executionTime;
    size_t index;

    Order(size_t t, size_t i) {
        executionTime = t;
        index = i;
    }
};

struct CanNotBeStarted {
    bool operator()(const Order& lhs, const Order& rhs) {
        return lhs.index > rhs.index;
    }
};

struct CanBeStarted {
    bool operator()(const Order& lhs, const Order& rhs) {
        return lhs.executionTime > rhs.executionTime;
    }
};

int main() {
    std::priority_queue<Order, vector<Order>, CanNotBeStarted> canNotBeStarted;
    std::priority_queue<Order, vector<Order>, CanBeStarted> canBeStarted;

    size_t queries;
    std::cin >> queries;

    for (size_t i = 0; i < queries; i++) {
        size_t current;
        std::cin >> current;
        canNotBeStarted.push(Order(current, i));
    }

    size_t currentTime = 0;
    size_t nextStart = 0;
    size_t min = 0, max = 0;
    min--; // to become ULL max
    while (!canNotBeStarted.empty() || !canBeStarted.empty()) {
        while (!canNotBeStarted.empty() && currentTime >= canNotBeStarted.top().index) {
            canBeStarted.push(canNotBeStarted.top());
            canNotBeStarted.pop();
        }

        if (!canBeStarted.empty() && nextStart <= currentTime) {
            Order next = canBeStarted.top();
            canBeStarted.pop();
            nextStart += next.executionTime;
            size_t currentExecTime = next.executionTime + currentTime - next.index;

            if (currentExecTime < min) {
                min = currentExecTime;
            }
            if (max < currentExecTime) {
                max = currentExecTime;
            }
        }

        currentTime++;
    }

    std::cout << min << " " << max;

    return 0;
}