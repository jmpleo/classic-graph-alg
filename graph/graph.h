#ifndef GRAPH_H
#define GRAPH_H

namespace Graph {

    struct Edge     { int u, v; };
    struct WtEdge : public Edge  { double weight; };

} // namespace Graph

#endif // GRAPH_H
