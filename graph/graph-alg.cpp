#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <boost/algorithm/cxx11/iota.hpp>
#include "graph-alg.h"
#include "graph.h"

    std::list<int>
    Graph::Algorithm::DeepFirstSearch(
            const std::vector< std::list<int> >& adjacencyLists,
            int vertex
            )
    {
        std::list<int> visitedList;
        std::vector<bool> alreadyVisited(adjacencyLists.size(), false);
        std::stack<int> vertexStack;
        vertexStack.push(vertex);

        while (!vertexStack.empty()) {
            vertex = vertexStack.top();
            vertexStack.pop();
            visitedList.push_back(vertex);
            alreadyVisited[vertex] = true;

            for (int adjacenctVertex : adjacencyLists[vertex]) {
                if (!alreadyVisited[vertex])
                    vertexStack.push(adjacenctVertex);
            }
        }
    }

    std::list<int>
    Graph::Algorithm::BreadthFirstSearch(
            const std::vector< std::list<int> > &adjacencyLists,
            int vertex
            )
    {
        std::list<int> visitedList;
        std::vector<bool> alreadyVisited(adjacencyLists.size(), false);
        std::queue<int> vertexQueue;
        vertexQueue.push(vertex);

        while (!vertexQueue.empty()) {
            vertex = vertexQueue.front();
            vertexQueue.pop();
            visitedList.push_back(vertex);
            alreadyVisited[vertex] = true;

            for (int adjacencyVertex : adjacencyLists[vertex]) {
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

    std::vector< double >
    Graph::Algorithm::DijkstraShortedPath(
            const std::vector< std::vector<double> > &wtMatrix,
            int vertex,
            size_t numVertex
            )
    {
        int vertexCount = 1;
        int vertexMinDist, j, i;

        std::vector<double> distances(numVertex);
        for (i = 0; i < numVertex; ++i) {
            distances[i] = wtMatrix[vertex][i];
        }

        std::vector<int> nearestVertex(numVertex, 0);
        nearestVertex[vertex] = 1;

        while (vertexCount < numVertex) {

            j = 0;
            while (nearestVertex[j] != 0) ++j;

            vertexMinDist = j;
            for (i = j + 1; i < numVertex; ++i) {
                if (nearestVertex[i] == 0
                    && distances[vertexMinDist] > distances[i]) {
                        vertexMinDist = i;
                }
            }

            nearestVertex[vertexMinDist] = 1;
            ++vertexCount;

            for (j = 1; j < numVertex; ++j) {
                if (nearestVertex[j] == 0) {
                    if (distances[j] > distances[vertexMinDist] + wtMatrix[vertexMinDist][j])
                        distances[j] = distances[vertexMinDist] + wtMatrix[vertexMinDist][j];
                }
            }
        }
        return distances;
    }

