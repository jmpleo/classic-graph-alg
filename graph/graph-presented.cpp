#include "graph-presented.h"
#include <vector>

    std::vector< std::list<int> >
    Graph::Presented::AdjListPresented(
            std::vector< Edge > const& edgesList,
            size_t numVertex
            )
    {
        std::vector< std::list<int> > adjLists;
        for (int vertex = 0; vertex < numVertex; ++vertex) {
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

    std::vector< Graph::Edge >
    Graph::Presented::EdgesList(
            std::vector<std::list<int> > const& adjLists
            )
    {
        std::vector < Edge > edgesList;
        for (int vertex = 0; vertex < adjLists.size(); ++vertex) {
            for (int adjVertex : adjLists[vertex]) {
                edgesList.push_back({vertex, adjVertex});
            }
        }
        return edgesList;
    }
