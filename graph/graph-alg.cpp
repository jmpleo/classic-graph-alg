#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <boost/algorithm/cxx11/iota.hpp>
#include "graph-alg.h"
#include "graph.h"

    std::vector< size_t >
    Graph::Algorithm::DeepFirstSearch(
            std::vector< std::vector< size_t >> const& adjacencyLists,
            size_t vertex
            )
    {
        std::vector< size_t > visitedList;
        std::vector< bool > alreadyVisited(adjacencyLists.size(), false);
        std::stack< size_t > vertexStack;
        vertexStack.push(vertex);
        alreadyVisited[vertex] = true;

        while (!vertexStack.empty()) {
            vertex = vertexStack.top();
            vertexStack.pop();
            visitedList.push_back(vertex);

            for (size_t adjacencyVertex : adjacencyLists[vertex]) {
                if (!alreadyVisited[adjacencyVertex]) {
                    alreadyVisited[adjacencyVertex] = true;
                    vertexStack.push(adjacencyVertex);
                }
            }
        }
        return visitedList;
    }

    std::vector< size_t >
    Graph::Algorithm::BreadthFirstSearch(
            std::vector< std::vector< size_t >> const &adjacencyLists,
            size_t vertex
            )
    {
        std::vector<size_t> visitedList;
        std::vector<bool> alreadyVisited(adjacencyLists.size(), false);
        std::queue<size_t> vertexQueue;
        alreadyVisited[vertex] = true;
        vertexQueue.push(vertex);

        while (!vertexQueue.empty()) {
            vertex = vertexQueue.front();
            vertexQueue.pop();
            visitedList.push_back(vertex);

            for (size_t adjacencyVertex : adjacencyLists[vertex]) {
                if (!alreadyVisited[adjacencyVertex]) {
                    alreadyVisited[adjacencyVertex] = true;
                    vertexQueue.push(adjacencyVertex);
                }
            }
        }
        return visitedList;
    }

    std::vector< Graph::WtEdge >
    Graph::Algorithm::KruskalsFindMinSpTree(
            std::vector< WtEdge >const & edges,
            size_t numVertex
            )
    {
        std::vector<WtEdge> minSpTree;
        std::vector<size_t> components(numVertex);
        boost::algorithm::iota(components.begin(), components.end(), 0);
        size_t numComp = edges.size();

        for (auto edge : edges) {
            if (numComp == 1) {
                break;
            }

            if (components[edge.u] != components[edge.v]) {
                for (size_t vertex = 0; vertex < numVertex; ++vertex) {
                    if (components[vertex] == components[edge.v]) {
                        components[vertex] = components[edge.u];
                    }
                }
                --numComp;
                minSpTree.push_back(edge);
            }
        }
        return minSpTree;
    }

    std::vector< double >
    Graph::Algorithm::DijkstraShortedPath(
            const std::vector< std::vector<double> > &wtMatrix,
            size_t vertex,
            size_t numVertex
            )
    {
        size_t vertexCount = 1;
        size_t vertexMinDist, j, i;

        std::vector<double> distances(numVertex);
        for (i = 0; i < numVertex; ++i) {
            distances[i] = wtMatrix[vertex][i];
        }

        std::vector<bool> nearestVertex(numVertex, false);
        nearestVertex[vertex] = true;

        while (vertexCount < numVertex) {

            j = 0;
            while (nearestVertex[j] != false) ++j;

            vertexMinDist = j;
            for (i = j + 1; i < numVertex; ++i) {
                if (nearestVertex[i] == false
                    && distances[vertexMinDist] > distances[i]) {
                        vertexMinDist = i;
                }
            }

            nearestVertex[vertexMinDist] = true;
            ++vertexCount;

            for (j = 1; j < numVertex; ++j) {
                if (nearestVertex[j] == false) {
                    if (distances[j] > distances[vertexMinDist] + wtMatrix[vertexMinDist][j])
                        distances[j] = distances[vertexMinDist] + wtMatrix[vertexMinDist][j];
                }
            }
        }
        return distances;
    }

