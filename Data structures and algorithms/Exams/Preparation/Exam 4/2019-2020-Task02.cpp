// Just copy pasted from 2020-2021 and it works
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Interval {
    size_t start, end;

    Interval(size_t start, size_t end) {
        this->start = start;
        this->end = end;
    }
};

struct Query {
    size_t time, index, available = 0;

    Query(size_t time, size_t index) {
        this->time = time;
        this->index = index;
    }
};

bool compareIntervals(const Interval& lhs, const Interval& rhs) {
    if (lhs.start == rhs.start) {
        return lhs.end < rhs.end;
    }

    return lhs.start < rhs.start;
}

bool compareQueriesByTime(const Query& lhs, const Query& rhs) {
    return lhs.time < rhs.time;
}

bool compareQueriesByIndex(const Query& lhs, const Query& rhs) {
    return lhs.index < rhs.index;
}

void print(const std::vector<Query> list) {
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list[i].available << " ";
    }
}

int main() {
    std::vector<Interval> intervalsContainer;
    size_t intervalsCount, queriesCount;
    std::cin >> intervalsCount >> queriesCount;

    for (size_t i = 0; i < intervalsCount; i++) {
        size_t start, end;
        std::cin >> start >> end;
        intervalsContainer.push_back(Interval(start, end));
    }

    std::sort(intervalsContainer.begin(), intervalsContainer.end(), compareIntervals);

    std::vector<Query> queries;
    for (size_t i = 0; i < queriesCount; i++) {
        size_t time;
        std::cin >> time;
        queries.push_back(Query(time, i));
    }

    std::sort(queries.begin(), queries.end(), compareQueriesByTime);

    std::priority_queue<size_t, vector<size_t>, greater<size_t>> currentIntervalEnds;
    size_t intervalIndex = 0, queryIndex = 0;

    while (queryIndex < queriesCount) {
        // remove useless from priority_queue
        while (!currentIntervalEnds.empty() && queries[queryIndex].time > currentIntervalEnds.top()) {
            currentIntervalEnds.pop();
        }

        // while possible try to add to intervals or else move to next one
        while (intervalIndex < intervalsContainer.size() &&
            intervalsContainer[intervalIndex].start <= queries[queryIndex].time) {
            if (queries[queryIndex].time <= intervalsContainer[intervalIndex].end) {
                currentIntervalEnds.push(intervalsContainer[intervalIndex].end);
            }

            intervalIndex++;
        }

        // assign and move to next queue
        queries[queryIndex++].available = currentIntervalEnds.size();
    }

    std::sort(queries.begin(), queries.end(), compareQueriesByIndex);
    print(queries);

    return 0;
}