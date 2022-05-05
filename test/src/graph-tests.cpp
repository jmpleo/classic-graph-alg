#include <cfloat>
#include <cstdio>
#include <gtest/gtest.h>
#include <vector>
#include <vector>

#include <graph.h>
#include <graph-alg.h>
#include <graph-presented.h>

using namespace Graph::Algorithm;
using namespace Graph::Presented;

TEST(GraphAlgorithmTests, DeepFirstSearchTest)
{
    size_t numVertex = 5;
    size_t vertex = 1;

    std::vector<size_t> expected = {1, 2, 3, 4, 0};
    std::vector <Graph::Edge> edgesList = {
        {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2},
        {2, 3}, {3, 4}
    };

    EXPECT_EQ(expected,
        DeepFirstSearch(ToAdjList(edgesList, numVertex), vertex));
};

TEST(GraphAlgorithmTests, BreadthFirstSearchTestTest)
{
    size_t numVertex = 5;
    size_t vertex = 1;

    std::vector<size_t> expected = {1, 0, 2, 3, 4};
    std::vector <Graph::Edge> edgesList = {
        {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2},
        {2, 3}, {3, 4}
    };

    EXPECT_EQ(expected,
        BreadthFirstSearch(ToAdjList(edgesList, numVertex), vertex));
};

TEST(GraphAlgorithmTests, KruskalsFindMinSpTreeTest)
{
    size_t numVertex = 5;

    std::vector< Graph::WtEdge > expected = {
        {0, 1, 1.}, {1, 2, 2.},
        {2, 3, 3.}, {3, 4, 4.}
    };

    std::vector< Graph::WtEdge > edgesList = {
        {0, 1, 1.}, {1, 2, 2.},
        {2, 3, 3.}, {3, 4, 4.},
        {4, 2, 5.}, {4, 1, 6.},
        {3, 1, 6.}
    };

    EXPECT_EQ(expected,
        KruskalsFindMinSpTree(edgesList, numVertex));
}

TEST(GraphAlgorithmTests, DijkstraShortedPathTest)
{
    std::vector< double > expected = {
        DBL_MAX, 1., 3., 6., 10
    };

    size_t numVertex = 5;
    size_t vertex = 0;

    std::vector< Graph::WtEdge > edgesList = {
        {0, 1, 1.}, {1, 2, 2.},
        {2, 3, 3.}, {3, 4, 4.},
        {4, 2, 5.}, {4, 1, 6.},
        {3, 1, 6.}
    };

    EXPECT_EQ(expected,
        DijkstraShortedPath(ToWtMatrix(edgesList, numVertex), vertex, numVertex));

}
