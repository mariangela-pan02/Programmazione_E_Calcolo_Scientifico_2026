#include <cassert>
#include <iostream>

#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"

int main()
{
    // Test normalizzazione arco
    {
        unidirected_edge e(5, 2);

        assert(e.from() == 2);
        assert(e.to() == 5);
    }

    // Test uguaglianza archi
    {
        unidirected_edge e1(1, 4);
        unidirected_edge e2(4, 1);

        assert(e1 == e2);
    }

    // Test neighbours
    {
        unidirected_graph g;

        g.add_edge({1, 2});
        g.add_edge({1, 3});

        auto neighbours = g.neighbours(1);

        assert(neighbours.size() == 2);
        assert(neighbours.contains(2));
        assert(neighbours.contains(3));
    }

    // Test duplicati
    {
        unidirected_graph g;

        g.add_edge({1, 2});
        g.add_edge({2, 1});

        assert(g.all_edges().size() == 1);
    }

    // Test all_nodes
    {
        unidirected_graph g;

        g.add_edge({1, 2});
        g.add_edge({2, 4});

        auto nodes = g.all_nodes();

        assert(nodes.size() == 3);

        assert(nodes.contains(1));
        assert(nodes.contains(2));
        assert(nodes.contains(4));
    }

    // Test edge_number e edge_at
    {
        unidirected_graph g;

        g.add_edge({1, 2});
        g.add_edge({1, 3});
        g.add_edge({2, 3});

        int index = g.edge_number({1, 3});

        assert(index != -1);

        assert(g.edge_at(index) ==
               unidirected_edge(1, 3));
    }

    // Test differenza grafi
    {
        unidirected_graph g1;

        g1.add_edge({1, 2});
        g1.add_edge({2, 3});
        g1.add_edge({3, 4});

        unidirected_graph g2;

        g2.add_edge({2, 3});

        auto diff = g1 - g2;

        auto edges = diff.all_edges();

        assert(edges.size() == 2);

        assert(edges.contains(
            unidirected_edge(1, 2)));

        assert(edges.contains(
            unidirected_edge(3, 4)));
    }

    std::cout << "All tests passed.\n";

    return 0;
}