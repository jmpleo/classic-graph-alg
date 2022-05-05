#ifndef GRAPH_H
#define GRAPH_H
#include <cstddef>

namespace Graph {

    struct Edge {
        Edge(size_t _u, size_t _v)
            : u(_u)
            , v(_v)
        {}

        bool operator==(Edge const& other) const
        {
            return (u == other.u && v == other.v)
               ||  (u == other.v && v == other.u);
        }

        size_t u, v;
    };

    struct WtEdge : public Edge {
        WtEdge(size_t u, size_t v, double wt)
            : Edge(u, v)
            , weight(wt)
        {}

        bool operator==(WtEdge const& other) const
        {
            return ((u == other.u && v == other.v)
                ||  (u == other.v && v == other.u))
                &&  (weight == other.weight);
        }

        double weight;
    };

} // namespace Graph

#endif // GRAPH_H
