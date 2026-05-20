#pragma once

#include <functional>
#include <limits>
#include <map>
#include <queue>
#include <vector>

#include "unidirected_graph.hpp"

struct dijkstra_result
{
    std::map<int, int> distances;
    unidirected_graph tree;
};

inline dijkstra_result dijkstra(const unidirected_graph& g,
                                int source)
{
    dijkstra_result result;
    std::map<int, int> predecessor;

    for (int node : g.all_nodes())
    {
        result.distances[node] =
            std::numeric_limits<int>::max();
    }

    result.distances[source] = 0;

    using pair = std::pair<int, int>;

    std::priority_queue<
        pair,
        std::vector<pair>,
        std::greater<pair>
    > pq;

    pq.push({0, source});

    while (!pq.empty())
    {
        auto [distance, current] = pq.top();
        pq.pop();

        if (distance > result.distances[current])
        {
            continue;
        }

        for (int neighbour : g.neighbours(current))
        {
            int new_distance =
                result.distances[current] + 1;

            if (new_distance <
                result.distances[neighbour])
            {
                result.distances[neighbour] =
                    new_distance;

                predecessor[neighbour] =
                    current;

                pq.push({new_distance, neighbour});
            }
        }
    }

    for (const auto& [node, parent] : predecessor)
    {
        result.tree.add_edge({parent, node});
    }

    return result;
}