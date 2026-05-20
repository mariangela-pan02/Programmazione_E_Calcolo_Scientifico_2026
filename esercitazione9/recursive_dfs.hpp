#pragma once

#include <set>

#include "unidirected_graph.hpp"

inline void recursive_dfs_visit(const unidirected_graph& g,
                                int current,
                                std::set<int>& visited,
                                unidirected_graph& tree)
{
    visited.insert(current);

    for (int neighbour : g.neighbours(current))
    {
        if (!visited.contains(neighbour))
        {
            tree.add_edge({current, neighbour});

            recursive_dfs_visit(g,
                                neighbour,
                                visited,
                                tree);
        }
    }
}

inline unidirected_graph recursive_dfs(const unidirected_graph& g,
                                       int source)
{
    unidirected_graph tree;

    std::set<int> visited;

    recursive_dfs_visit(g,
                        source,
                        visited,
                        tree);

    return tree;
}
