#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    size_t to, weight;
};

void dijkstra(std::vector<std::vector<Edge>>& graph, std::vector<size_t>& distances, size_t start) {
    struct tmp {
        size_t index, distance;

        bool operator<(const tmp& rhs) const {
            return distance > rhs.distance;
        }
    };
    std::priority_queue<tmp> nextToProcess;
    nextToProcess.push({ start, 0 });
    distances[start] = 0;

    while (!nextToProcess.empty()) {
        auto toProcess = nextToProcess.top();
        nextToProcess.pop();
        size_t current = toProcess.index;

        if (toProcess.distance > distances[current]) {
            continue;
        }

        for (auto& neighbour : graph[current]) {
            auto alternativeDistance = neighbour.weight + toProcess.distance;

            if (alternativeDistance < distances[neighbour.to]) {
                distances[neighbour.to] = alternativeDistance;
                nextToProcess.push({ neighbour.to, alternativeDistance });
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    size_t verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;

    std::vector<std::vector<Edge>> graph(verticesCount);
    for (size_t i = 0; i < edgesCount; i++) {
        size_t from, to, weight;
        std::cin >> from >> to >> weight;
        graph[from - 1].push_back({ to - 1, weight });
        graph[to - 1].push_back({ from - 1, weight });
    }

    size_t start;
    std::cin >> start;
    --start;

    std::vector<size_t> distances(verticesCount, ULLONG_MAX);
    dijkstra(graph, distances, start);

    for (size_t i = 0; i < distances.size(); i++) {
        if (i != start) {
            if(distances[i] == ULLONG_MAX) std::cout << -1 << " ";
            else std::cout << distances[i] << " ";

        }
    }

    return 0;
}
