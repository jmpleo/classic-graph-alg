#ifndef GRAPH_PRESENTED_H
#define GRAPH_PRESENTED_H

#include "graph.h"
#include <vector>
#include <list>

namespace Graph { namespace Presented {

    /// NOTE: expected that the graph haven't multiply edges
    std::vector< std::list<int> >
    AdjListPresented(
            std::vector< Edge > const& edgesList,
            size_t numVertex
            );

    /// NOTE: return edges list is contains a multiply edge
    std::vector< Edge >
    EdgesList(
            std::vector< std::list<int> > const&
            );

}} // namespace Graph::Presented

#endif // GRAPH_PRESENTED_H
