#include <cassert>
#include <iostream>

#include "dijkstra.hpp"
#include "fifo.hpp"
#include "graph_visit.hpp"
#include "lifo.hpp"
#include "recursive_dfs.hpp"
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"

int main()
{
    unidirected_graph g;

    g.add_edge({1, 2});
    g.add_edge({1, 3});
    g.add_edge({2, 4});
    g.add_edge({2, 5});
    g.add_edge({3, 6});

    {
        fifo<int> q;

        auto bfs_tree =
            graph_visit(g, 1, q);

        assert(bfs_tree.all_edges().size() == 5);
    }

    {
        lifo<int> s;

        auto dfs_tree =
            graph_visit(g, 1, s);

        assert(dfs_tree.all_edges().size() == 5);
    }

    {
        auto recursive_tree =
            recursive_dfs(g, 1);

        assert(recursive_tree.all_edges().size() == 5);
    }

    {
        auto result =
            dijkstra(g, 1);

        assert(result.distances[1] == 0);
        assert(result.distances[2] == 1);
        assert(result.distances[3] == 1);
        assert(result.distances[4] == 2);
        assert(result.distances[5] == 2);
        assert(result.distances[6] == 2);

        auto tree_edges =
            result.tree.all_edges();

        assert(tree_edges.size() == 5);

        assert(tree_edges.contains(
            unidirected_edge(1, 2)
        ));

        assert(tree_edges.contains(
            unidirected_edge(1, 3)
        ));

        assert(tree_edges.contains(
            unidirected_edge(2, 4)
        ));

        assert(tree_edges.contains(
            unidirected_edge(2, 5)
        ));

        assert(tree_edges.contains(
            unidirected_edge(3, 6)
        ));
    }

    std::cout << "All tests passed.\n";

    return 0;
}