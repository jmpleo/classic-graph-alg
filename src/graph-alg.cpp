#include <stack>
#include <queue>
#include <utility>
#include <vector>
#include "graph-alg.h"


    void
    DeepFirstSearch(
            const std::map< int, std::list<int> >& adjacencyLists,
            std::list<int>& visitedList,
            int vertex
            )
    {
        std::map<int, bool> alreadyVisited;
        for (auto vertexAndList : adjacencyLists)
            alreadyVisited[vertexAndList.first] = false;

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
    BreadthFirstSearch(
            const std::map<int, std::list<int> > &adjacencyLists,
            std::list<int> &visitedList,
            int vertex
            )
    {
        std::map<int, bool> alreadyVisited;
        for (auto vertexAndList : adjacencyLists)
            alreadyVisited[vertexAndList.first] = false;

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

    std::vector< wtEdge >
    KruskalsFindMinSpTree(
            const std::vector< wtEdge >& edges
            )
    {
        std::vector<wtEdge> minSpTree;
        std::vector<wtEdge> availableEdges(edges);

        while (!availableEdges.empty())
        {

        }

    }

