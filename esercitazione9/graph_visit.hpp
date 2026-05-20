#pragma once

#include <set>

#include "unidirected_graph.hpp"

template<typename Container>
unidirected_graph graph_visit(const unidirected_graph& g,
                                 int source,
                                 Container container)
{
    unidirected_graph tree;

    std::set<int> visited;

    container.put(source);

    visited.insert(source);

    while (!container.empty())
    {
        int current = container.get();

        for (int neighbour : g.neighbours(current))
        {
            if (!visited.contains(neighbour))
            {
                visited.insert(neighbour);

                tree.add_edge({current, neighbour});

                container.put(neighbour);
            }
        }
    }

    return tree;
}
