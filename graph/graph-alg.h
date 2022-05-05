#ifndef GRAPH_ALG_H
#define GRAPH_ALG_H

#include "graph.h"
#include <vector>
#include <map>
#include <list>

namespace Graph { namespace Algorithm {

    std::vector< size_t >
    DeepFirstSearch(
            std::vector< std::vector<size_t> > const& adjacencyList,
            size_t startVertex
            );

    std::vector< size_t >
    BreadthFirstSearch(
            std::vector< std::vector<size_t> > const& adjacencyList,
            size_t startVertex
            );

    /// NOTE: expected that the edges are already sorted by weight
    std::vector< WtEdge >
    KruskalsFindMinSpTree(
            std::vector< WtEdge > const& edges,
            size_t numVertex
            );

    std::vector < double >
    DijkstraShortedPath(
            std::vector< std::vector<double> > const& wtMatrix,
            size_t vertex,
            size_t numVertex
            );

}} // namespace Graph::Algorithm

#endif // GRAPH_ALG_H
