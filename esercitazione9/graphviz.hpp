#pragma once

#include <fstream>
#include <string>

#include "unidirected_graph.hpp"

inline void write_graphviz(const unidirected_graph& g,
                           const std::string& filename)
{
    std::ofstream output(filename);

    output << "graph G {\n";

    for (const auto& e : g.all_edges())
    {
        output << "    "
               << e.from()
               << " -- "
               << e.to()
               << ";\n";
    }

    output << "}\n";
}