#include "graph-presented.h"
#include "graph.h"
#include <cfloat>
#include <vector>

    std::vector< std::vector< size_t >>
    Graph::Presented::ToAdjList(
            std::vector< Edge > const& edgesList,
            size_t numVertex
            )
    {
        std::vector< std::vector< size_t >> adjLists(numVertex);
        for (size_t vertex = 0; vertex < numVertex; ++vertex) {
            for (Edge edge : edgesList) {
                if (vertex == edge.u) {
                    adjLists[vertex].push_back(edge.v);
                }
                else if (vertex == edge.v) {
                    adjLists[vertex].push_back(edge.u);
                }
            }
        }
        return adjLists;
    }

    std::vector< std::vector< double >>
    Graph::Presented::ToWtMatrix(
            std::vector< WtEdge > const& edgesList,
            size_t numVertex
            )
    {
        std::vector< std::vector < double >> wtMatrix(numVertex,
                std::vector< double >(numVertex, DBL_MAX));

        for (WtEdge edge : edgesList) {
            wtMatrix[edge.u][edge.v] = edge.weight;
        }
        return wtMatrix;
    }
