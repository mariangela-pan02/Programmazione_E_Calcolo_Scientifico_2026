#include <iostream>

#include "unidirected_graph.hpp"

int main()
{
    unidirected_graph g;

    std::cout << "=== FIRST GRAPH ===\n";

    std::cout << "Edges added:\n";
    std::cout << "{1, 2}\n";
    std::cout << "{3, 2}\n";
    std::cout << "{1, 3}\n";
    std::cout << "{5, 1}\n";
    std::cout << "{3, 4}\n";
    std::cout << "{2, 1}\n\n";

    g.add_edge({1, 2});
    g.add_edge({3, 2});
    g.add_edge({1, 3});
    g.add_edge({5, 1});
    g.add_edge({3, 4});
    g.add_edge({2, 1});

    std::cout << "All edges:\n";

    for (const auto& e : g.all_edges())
    {
        std::cout << e << '\n';
    }

    std::cout << "\nAll nodes:\n";

    for (int n : g.all_nodes())
    {
        std::cout << n << ' ';
    }

    std::cout << "\n\nNeighbours:\n";

    for (int node : g.all_nodes())
    {
        std::cout << "Neighbours of " << node << ": ";

        for (int neighbour : g.neighbours(node))
        {
            std::cout << neighbour << ' ';
        }

        std::cout << '\n';
    }

    std::cout << "\nEdge numbers:\n";

    int index = 0;

    for (const auto& e : g.all_edges())
    {
        std::cout << "edge_at(" << index << ") = "
                  << g.edge_at(index)
                  << ", edge_number(" << e << ") = "
                  << g.edge_number(e)
                  << '\n';

        ++index;
    }

    unidirected_graph g2;

    std::cout << "\n=== SECOND GRAPH ===\n";

    std::cout << "Edges added:\n";
    std::cout << "{1, 2}\n";
    std::cout << "{3, 2}\n\n";

    g2.add_edge({1, 2});
    g2.add_edge({3, 2});

    std::cout << "All edges:\n";

    for (const auto& e : g2.all_edges())
    {
        std::cout << e << '\n';
    }

    std::cout << "\nAll nodes:\n";

    for (int n : g2.all_nodes())
    {
        std::cout << n << ' ';
    }

    std::cout << "\n\nNeighbours:\n";

    for (int node : g2.all_nodes())
    {
        std::cout << "Neighbours of " << node << ": ";

        for (int neighbour : g2.neighbours(node))
        {
            std::cout << neighbour << ' ';
        }

        std::cout << '\n';
    }

    const unidirected_graph diff = g - g2;

    std::cout << "\n=== DIFFERENCE g - g2 ===\n";

    std::cout << "Edges in the first graph and not in the second graph:\n";

    for (const auto& e : diff.all_edges())
    {
        std::cout << e << '\n';
    }

    return 0;
}