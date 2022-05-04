#ifndef GRAPH_ALG_H
#define GRAPH_ALG_H

#include "graph.h"
#include <vector>
#include <map>
#include <list>

namespace Graph { namespace Algorithm {

    void
    DeepFirstSearch(
            const std::vector< std::list<int> >& adjacencyList,
            std::list< int >& visited,
            int startVertex
            );

    void
    BreadthFirstSearch(
            const std::vector< std::list<int> >& adjacencyList,
            std::list< int >& visited,
            int startVertex
            );

    /// NOTE: expected that the edges are already sorted by weight
    std::vector< Edge >
    KruskalsFindMinSpTree(
            const std::vector< Edge >& edges,
            size_t numVertex
            );

}} // Graph::Algorithm

#endif // GRAPH_ALG_H
