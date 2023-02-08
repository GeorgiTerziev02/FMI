#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

void dijkstra(std::vector<std::vector<size_t>>& graph, std::vector<size_t>& distances, size_t start) {
    struct tmp {
        size_t index, weightTo;

        bool operator<(const tmp& rhs) const {
            return this->weightTo < rhs.weightTo;
        }
    };
    std::priority_queue<tmp> toProcess;
    toProcess.push({ start, 0 });
    distances[start] = 0;

    while (!toProcess.empty()) {
        auto current = toProcess.top();
        toProcess.pop();

        if (distances[current.index] < current.weightTo) {
            continue;
        }

        for (auto& adj : graph[current.index]) {
            size_t alternativeDistance = current.weightTo + 6;

            if (alternativeDistance < distances[adj]) {
                toProcess.push({ adj, alternativeDistance });
                distances[adj] = alternativeDistance;
            }
        }
    }
}

int main() {
    size_t queriesCount;
    std::cin >> queriesCount;

    for (size_t i = 0; i < queriesCount; i++) {
        size_t verticesCount, edgesCount;
        std::cin >> verticesCount >> edgesCount;

        std::vector<std::vector<size_t>> graph(verticesCount);
        for (size_t j = 0; j < edgesCount; j++) {
            size_t from, to;
            std::cin >> from >> to;
            graph[from - 1].push_back(to - 1);
            graph[to - 1].push_back(from - 1);
        }

        size_t start;
        std::cin >> start;
        --start;

        std::vector<size_t> distances(verticesCount, ULLONG_MAX);

        dijkstra(graph, distances, start);

        for (size_t j = 0; j < distances.size(); j++) {
            if (j == start) {
                continue;
            }

            if(distances[j] == ULLONG_MAX) {
                std::cout << -1 << " ";
            }
            else {
                std::cout << distances[j] << " ";
            }
        }

        std::cout << '\n';
    }

    return 0;
}