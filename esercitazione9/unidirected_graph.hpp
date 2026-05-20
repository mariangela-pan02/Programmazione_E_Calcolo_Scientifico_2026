#pragma once

#include <set>
#include <map>
#include <iterator>

#include "unidirected_edge.hpp"

class unidirected_graph
{
private:
    std::set<unidirected_edge> edges_;

    std::map<int, std::set<int>> adjacency_;

public:
    unidirected_graph() = default;

    unidirected_graph(const unidirected_graph&) = default;

    void add_edge(const unidirected_edge& e)
    {
        edges_.insert(e);

        adjacency_[e.from()].insert(e.to());
        adjacency_[e.to()].insert(e.from());
    }

    std::set<int> neighbours(int node) const
    {
        auto it = adjacency_.find(node);

        if (it == adjacency_.end())
        {
            return {};
        }

        return it->second;
    }

    std::set<unidirected_edge> all_edges() const
    {
        return edges_;
    }

    std::set<int> all_nodes() const
    {
        std::set<int> nodes;

        for (const auto& pair : adjacency_)
        {
            nodes.insert(pair.first);
        }

        return nodes;
    }

    int edge_number(const unidirected_edge& e) const
    {
        int index = 0;

        for (const auto& edge : edges_)
        {
            if (edge == e)
            {
                return index;
            }

            ++index;
        }

        return -1;
    }

    unidirected_edge edge_at(int index) const
    {
        auto it = edges_.begin();

        std::advance(it, index);

        return *it;
    }

    unidirected_graph operator-(const unidirected_graph& other) const
    {
        unidirected_graph result;

        for (const auto& edge : edges_)
        {
            if (other.edges_.find(edge) == other.edges_.end())
            {
                result.add_edge(edge);
            }
        }

        return result;
    }
};