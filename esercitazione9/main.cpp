#include <iostream>

#include "dijkstra.hpp"
#include "fifo.hpp"
#include "graph_visit.hpp"
#include "graphviz.hpp"
#include "lifo.hpp"
#include "recursive_dfs.hpp"
#include "unidirected_graph.hpp"

int main()
{
    unidirected_graph g;

    g.add_edge({1, 2});
    g.add_edge({1, 3});
    g.add_edge({2, 4});
    g.add_edge({2, 5});
    g.add_edge({3, 6});
    g.add_edge({4, 6});
    g.add_edge({4, 7});
    g.add_edge({5, 8});
    g.add_edge({6, 9});
    g.add_edge({3, 10});

    fifo<int> q;

    auto bfs_tree =
        graph_visit(g, 1, q);

    std::cout << "BFS tree:\n";

    for (const auto& e :
         bfs_tree.all_edges())
    {
        std::cout << e << '\n';
    }

    std::cout << '\n';

    lifo<int> s;

    auto dfs_tree =
        graph_visit(g, 1, s);

    std::cout << "DFS tree:\n";

    for (const auto& e :
         dfs_tree.all_edges())
    {
        std::cout << e << '\n';
    }

    std::cout << '\n';

    auto recursive_tree =
        recursive_dfs(g, 1);

    std::cout << "Recursive DFS tree:\n";

    for (const auto& e :
         recursive_tree.all_edges())
    {
        std::cout << e << '\n';
    }

    std::cout << '\n';

    auto result =
        dijkstra(g, 1);

    write_graphviz(bfs_tree, "bfs.dot");

    write_graphviz(dfs_tree, "dfs.dot");

    write_graphviz(result.tree,
                   "dijkstra.dot");

    std::cout << "Dijkstra distances:\n";

    for (const auto& [node, distance]
         : result.distances)
    {
        std::cout << "Distance from 1 to "
                  << node
                  << " = "
                  << distance
                  << '\n';
    }

    std::cout << '\n';

    std::cout << "Dijkstra shortest path tree:\n";

    for (const auto& e :
         result.tree.all_edges())
    {
        std::cout << e << '\n';
    }

    return 0;
}