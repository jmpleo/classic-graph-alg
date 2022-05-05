#ifndef GRAPH_PRESENTED_H
#define GRAPH_PRESENTED_H

#include "graph.h"
#include <vector>
#include <list>

namespace Graph { namespace Presented {

    /// NOTE: expected that the graph haven't multiply edges
    std::vector< std::vector< size_t >>
    ToAdjList(
            std::vector< Edge > const& edgesList,
            size_t numVertex
            );

    std::vector< std::vector< double >>
    ToWtMatrix(
            std::vector< WtEdge > const& edgesList,
            size_t numVertex
            );

}} // namespace Graph::Presented

#endif // GRAPH_PRESENTED_H
