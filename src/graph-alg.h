#ifndef GRAPH_ALG_H
#define GRAPH_ALG_H

#include <vector>
#include <map>
#include <list>

    struct wtEdge {
        int u, v, weight;
    };

    void
    DeepFirstSearch(
            const std::map< int, std::list<int> >& adjacencyList,
            std::list< int >& visited,
            int startVertex
            );

    void
    BreadthFirstSearch(
            const std::map< int, std::list<int> >& adjacencyList,
            std::list< int >& visited,
            int startVertex
            );

    /// NOTE: expected thar the edges are already sorted
    std::vector< wtEdge >
    KruskalsFindMinSpTree(
            const std::vector< wtEdge >& edges
            );


#endif // GRAPH_ALG_H
