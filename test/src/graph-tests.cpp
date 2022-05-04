#include "graph-tests.h"
#include <gtest/gtest.h>
#include <tuple>

using namespace Graph::Algorithm;
using namespace Graph::Presented;

TEST_P(GraphAlgorithmTests, BreadthFirstSearchTest)
{
    auto expected = std::get<0>(GetParam());
    auto edgeList = std::get<1>(GetParam());
    auto numVertex = std::get<2>(GetParam());

    EXPECT_EQ(
        expected,
        BreadthFirstSearch(AdjListPresented(edgeList, numVertex), 0)
        );
};










