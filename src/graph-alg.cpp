#include <stack>
#include <queue>
#include <vector>
#include <boost/algorithm/cxx11/iota.hpp>
#include "graph-alg.h"
#include "graph.h"

    void
    Graph::Algorithm::DeepFirstSearch(
            const std::vector< std::list<int> >& adjacencyLists,
            std::list<int>& visitedList,
            int vertex
            )
    {
        std::vector<bool> alreadyVisited(adjacencyLists.size(), false);
        std::stack<int> vertexStack;
        vertexStack.push(vertex);

        while (!vertexStack.empty()) {
            vertex = vertexStack.top();
            vertexStack.pop();
            visitedList.push_back(vertex);
            alreadyVisited[vertex] = true;

            for (auto adjacenctVertex : adjacencyLists[vertex]) {
                if (!alreadyVisited[vertex])
                    vertexStack.push(adjacenctVertex);
            }
        }
    }

    void
    Graph::Algorithm::BreadthFirstSearch(
            const std::vector< std::list<int> > &adjacencyLists,
            std::list<int> &visitedList,
            int vertex
            )
    {
        std::vector<bool> alreadyVisited(adjacencyLists.size(), false);
        std::queue<int> vertexQueue;
        vertexQueue.push(vertex);

        while (!vertexQueue.empty()) {
            vertex = vertexQueue.front();
            vertexQueue.pop();
            visitedList.push_back(vertex);
            alreadyVisited[vertex] = true;

            for (auto adjacencyVertex : adjacencyLists[vertex]) {
                if (!alreadyVisited[vertex])
                    vertexQueue.push(adjacencyVertex);
            }
        }
    }

    std::vector< Graph::Edge >
    Graph::Algorithm::KruskalsFindMinSpTree(
            const std::vector< Edge >& edges,
            size_t numVertex
            )
    {
        std::vector<Edge> minSpTree;
        std::vector<int> components(numVertex);
        boost::algorithm::iota(components.begin(), components.end(), 1);
        int numComp = edges.size();

        for (auto edge : edges) {
            if (numComp == 1) {
                break;
            }
            if (components[edge.u] != components[edge.v]) {
                for (int vertex = 0; vertex < numVertex; ++vertex) {
                    if (components[vertex] == components[edge.v]) {
                        components[vertex] = components[edge.u];
                    }
                --numComp;
                minSpTree.push_back(edge);
                }
            }
        }
        return minSpTree;
    }

