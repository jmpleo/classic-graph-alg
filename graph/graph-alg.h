#ifndef GRAPH_ALG_H
#define GRAPH_ALG_H

#include "graph.h"
#include <vector>
#include <map>
#include <list>

namespace Graph { namespace Algorithm {

    std::list< int >
    DeepFirstSearch(
            const std::vector< std::list<int> >& adjacencyList,
            int startVertex
            );

    std::list< int >
    BreadthFirstSearch(
            const std::vector< std::list<int> >& adjacencyList,
            int startVertex
            );

    /// NOTE: expected that the edges are already sorted by weight
    std::vector< Edge >
    KruskalsFindMinSpTree(
            const std::vector< Edge >& edges,
            size_t numVertex
            );

    std::vector < double >
    DijkstraShortedPath(
            const std::vector< std::vector<double> >& wtMatrix,
            int vertex,
            size_t numVertex
            );

}} // namespace Graph::Algorithm

#endif // GRAPH_ALG_H
